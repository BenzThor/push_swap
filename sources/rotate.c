/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:13:29 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/07 13:04:48 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_sort *sort, int print)
{
	t_stack	*temp;
	t_stack	*last;

	if (sort->stack_a)
	{
		if (sort->stack_a->ptr)
		{
			temp = sort->stack_a;
			sort->stack_a = sort->stack_a->ptr;
			last = ft_stack_last(&sort->stack_a);
			last->ptr = temp;
			temp->ptr = NULL;
		}
	}
	if (print == 1)
		ft_putstr_fd("ra\n", 1);
}

void	ft_rotate_b(t_sort *sort, int print)
{
	t_stack	*temp;
	t_stack	*last;

	if (sort->stack_b)
	{
		if (sort->stack_b->ptr)
		{
			temp = sort->stack_b;
			sort->stack_b = sort->stack_b->ptr;
			last = ft_stack_last(&sort->stack_b);
			last->ptr = temp;
			temp->ptr = NULL;
		}
	}
	if (print == 1)
		ft_putstr_fd("rb\n", 1);
}

void	ft_rotate_both(t_sort *sort)
{
	ft_rotate_a(sort, 0);
	ft_rotate_b(sort, 0);
	ft_putstr_fd("rr\n", 1);
}
