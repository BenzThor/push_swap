/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:07:30 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/10 12:02:46 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_determine_cost(t_stack *stack, t_sort *sort)
{
	int		mid;
	int		elem;
	t_stack	*temp;

	temp = stack;
	elem = ft_stack_elements(stack, sort);
	if (elem % 2 == 1)
		mid = (elem / 2) + 1;
	else
		mid = elem / 2;
	while (stack)
	{
		if (stack->st_pos < mid)
		{
			stack->cost = stack->st_pos - 1;
			stack->a_md = 1;
		}
		else
		{
			stack->cost = stack->st_pos - elem;
			stack->a_md = 0;
		}
		stack = stack->ptr;
	}
	stack = temp;
}

void	ft_determine_cost_both(t_sort *sort)
{
	ft_determine_cost(sort->st_a, sort);
	ft_determine_cost(sort->st_b, sort);
}

int	ft_dist_to_top(t_stack *elem, int elem_num)
{
	int	d_top;

	if (elem->a_md == 1)
		d_top = elem->st_pos - 1;
	if (elem->a_md == 0)
		d_top = elem_num - elem->st_pos + 1;
	elem->d_top = d_top;
}

int	ft_hlvd_costs(t_stack *elem1, t_stack *elem2)
{
	int	hlvd_cost;

	if (elem1->a_md == 1 && elem1->a_md == elem2->a_md || elem1->a_md == 0
		&& elem1->a_md == elem2->a_md)
	{
		if (elem1->d_top <= elem2->d_top)
			hlvd_cost = elem1->d_top;
		else
			hlvd_cost = elem2->d_top;
	}
	return (hlvd_cost);
}

int	ft_determine_comb_cost(t_stack *p_st, int pst_elem, int tst_elem)
{
	t_stack	*temp;
	int		comb_cost;
	int		hlvd_cst;

	temp = p_st;
	comb_cost = 1000;
	while (p_st)
	{
		ft_dist_to_top(p_st, pst_elem);
		ft_dist_to_top(p_st->trgt, tst_elem);
		if (p_st->a_md == 1 && p_st->a_md == p_st->a_md)
			hlvd_cst = ft_hlvd_costs(p_st, p_st->trgt);
		p_st->comb_cost = p_st->cost + p_st->trgt->cost - hlvd_cst;
		p_st->trgt->comb_cost = p_st->comb_cost - hlvd_cst;
		if (p_st->comb_cost < comb_cost)
			comb_cost = p_st->comb_cost;
		p_st = p_st->ptr;
	}
	p_st = temp;
	return (comb_cost);
}
