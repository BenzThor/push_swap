/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:01:37 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/12 11:25:11 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack	*ft_stack_second_last(t_stack **st_add, t_stack **last_address)
{
	t_stack	*stack;

	stack = *st_add;
	while (stack->ptr && stack->ptr != *last_address)
		stack = stack->ptr;
	return (stack);
}

int	ft_reverse_rotate_a(t_sort *sort)
{
	t_stack	*last;
	t_stack	*second_last;

	if (sort->st_a)
	{
		if (sort->st_a->ptr)
		{
			last = ft_stack_last(&sort->st_a);
			second_last = ft_stack_second_last(&sort->st_a, &last);
			second_last->ptr = NULL;
			last->ptr = sort->st_a;
			sort->st_a = last;
		}
		return (1);
	}
	return (1);
}

int	ft_reverse_rotate_b(t_sort *sort)
{
	t_stack	*last;
	t_stack	*second_last;

	if (sort->st_b)
	{
		if (sort->st_b->ptr)
		{
			last = ft_stack_last(&sort->st_b);
			second_last = ft_stack_second_last(&sort->st_b, &last);
			second_last->ptr = NULL;
			last->ptr = sort->st_b;
			sort->st_b = last;
		}
		return (1);
	}
	return (1);
}

int	ft_reverse_rotate_both(t_sort *sort)
{
	ft_reverse_rotate_a(sort);
	ft_reverse_rotate_b(sort);
	return (1);
}
