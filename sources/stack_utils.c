/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:02:02 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/10 11:46:46 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_elements(t_stack *stack, t_sort *sort)
{
	int		elem_num;
	t_stack	*temp;

	temp = stack;
	elem_num = 0;
	while (stack)
	{
		elem_num++;
		stack->st_pos = elem_num;
		stack = stack->ptr;
	}
	stack = temp;
	if (sort->st_a == stack)
		sort->elem_a = elem_num;
	else
		sort->elem_b = elem_num;
	return (elem_num);
}

void	ft_stack_elements_both(t_sort *sort)
{
	ft_stack_elements(sort->st_a, sort);
	ft_stack_elements(sort->st_b, sort);
}

t_stack	*ft_stack_highest(t_stack *stack)
{
	t_stack	*highest;
	t_stack	*temp;

	temp = stack;
	highest = stack;
	while (stack)
	{
		if (stack->i > highest->i)
			highest = stack;
		stack = stack->ptr;
	}
	stack = temp;
	return (highest);
}

t_stack	*ft_stack_lowest(t_stack *stack)
{
	t_stack	*lowest;
	t_stack	*temp;

	temp = stack;
	lowest = stack;
	while (stack)
	{
		if (stack->i < lowest->i)
			lowest = stack;
		stack = stack->ptr;
	}
	stack = temp;
	return (lowest);
}
