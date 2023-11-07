/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:01:37 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/07 15:46:42 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_second_last(t_stack **st_add, t_stack **last_address)
{
	t_stack	*stack;

	stack = *st_add;
	while (stack->ptr && stack->ptr != *last_address)
		stack = stack->ptr;
	return (stack);
}

void	ft_reverse_rotate_a(t_sort *sort, int print)
{
	t_stack	*last;
	t_stack	*second_last;

	if (sort->stack_a)
	{
		if (sort->stack_a->ptr)
		{
			last = ft_stack_last(&sort->stack_a);
			second_last = ft_stack_second_last(&sort->stack_a, &last);
			second_last->ptr = NULL;
			last->ptr = sort->stack_a;
			sort->stack_a = last;
		}
	}
	if (print == 1)
		ft_putstr_fd("rra\n", 1);
}

void	ft_reverse_rotate_b(t_sort *sort, int print)
{
	t_stack	*last;
	t_stack	*second_last;

	if (sort->stack_b)
	{
		if (sort->stack_b->ptr)
		{
			last = ft_stack_last(&sort->stack_b);
			second_last = ft_stack_second_last(&sort->stack_b, &last);
			second_last->ptr = NULL;
			last->ptr = sort->stack_b;
			sort->stack_b = last;
		}
	}
	if (print == 1)
		ft_putstr_fd("rrb\n", 1);
}

void	ft_reverse_rotate_both(t_sort *sort)
{
	ft_reverse_rotate_a(sort, 0);
	ft_reverse_rotate_b(sort, 0);
	ft_putstr_fd("rrr\n", 1);
}
