/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:02:02 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/09 12:26:22 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_elements(t_stack *stack)
{
	int		elem_num;
	t_stack	*temp;

	temp = stack;
	elem_num = 0;
	while (stack)
	{
		elem_num++;
		stack->stack_pos = elem_num;
		stack = stack->ptr;
	}
	stack = temp;
	return (elem_num);
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

void	ft_stack_ind(t_stack *stack)
{
	t_stack	*temp1;
	t_stack	*temp2;
	int		ind;

	temp1 = stack;
	while (stack)
	{
		temp2 = temp1;
		ind = 0;
		while(temp2)
		{
			if (stack->i > temp2->i)
				ind++;
			temp2 = temp2->ptr;
		}
		stack->st_ind = ind;
		stack = stack->ptr;
	}
	stack = temp1;
}
