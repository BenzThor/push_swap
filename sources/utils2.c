/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:27:59 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/09 18:00:53 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a_to_b(t_sort *sort, int next_cost)
{

}

int	ft_determine_comb_cost(t_stack *push_st)
{
	t_stack	*temp;
	int		comb_cost;

	temp = push_st;
	comb_cost = 1000;
	while (push_st)
	{
		push_st->comb_cost = push_st->cost + push_st->trgt->cost;
		push_st->trgt->comb_cost = push_st->comb_cost;
		if (push_st->comb_cost < comb_cost)
			comb_cost = push_st->comb_cost;
		push_st = push_st->ptr;
	}
	push_st = temp;
}

void	ft_determine_cost(t_stack *stack)
{
	int		mid;
	int		elem;
	t_stack	*temp;

	temp = stack;
	elem = ft_stack_elements(stack);
	if (elem % 2 == 1)
		mid = (elem / 2) + 1;
	else
		mid = elem / 2;
	while (stack)
	{
		if (stack->stack_pos < mid)
			stack->cost = stack->stack_pos - 1;
		else
			stack->cost = stack->stack_pos - elem;
		stack = stack->ptr;
	}
	stack = temp;
}
