/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:07:30 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/10 17:47:25 by tbenz            ###   ########.fr       */
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
		if (stack->st_pos <= mid)
		{
			stack->cost = stack->st_pos - 1;
			stack->a_md = 1;
		}
		else
		{
			stack->cost = elem - stack->st_pos + 1;
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

int	ft_hlvd_costs(t_stack *elem1, t_stack *elem2)
{
	int	hlvd_cost;

	hlvd_cost = 0;
	if (elem1->a_md == elem2->a_md)
	{
		if (elem1->cost <= elem2->cost)
			hlvd_cost = elem1->cost;
		else
			hlvd_cost = elem2->cost;
	}
	return (hlvd_cost);
}

int	ft_determine_comb_cost(t_stack *p_st)
{
	t_stack	*temp;
	int		comb_cost;
	int		hlvd_cst;

	temp = p_st;
	comb_cost = 1000;
	while (p_st)
	{
		if (p_st->a_md == p_st->trgt->a_md)
			hlvd_cst = ft_hlvd_costs(p_st, p_st->trgt);
		else
			hlvd_cst = 0;
		p_st->comb_cost = p_st->cost + p_st->trgt->cost - hlvd_cst;
		p_st->trgt->comb_cost = p_st->comb_cost - hlvd_cst;
		if (p_st->comb_cost < comb_cost)
			comb_cost = p_st->comb_cost;
		p_st = p_st->ptr;
	}
	p_st = temp;
	return (comb_cost);
}
