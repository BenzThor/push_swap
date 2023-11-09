/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:13:29 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/09 12:11:36 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_sort *sort, int print)
{
	t_stack	*temp;
	t_stack	*last;

	if (sort->st_a)
	{
		if (sort->st_a->ptr)
		{
			temp = sort->st_a;
			sort->st_a = sort->st_a->ptr;
			last = ft_stack_last(&sort->st_a);
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

	if (sort->st_b)
	{
		if (sort->st_b->ptr)
		{
			temp = sort->st_b;
			sort->st_b = sort->st_b->ptr;
			last = ft_stack_last(&sort->st_b);
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
