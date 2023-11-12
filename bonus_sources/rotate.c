/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:13:29 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/12 11:25:49 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_rotate_a(t_sort *sort)
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
		return (1);
	}
	return (1);
}

int	ft_rotate_b(t_sort *sort)
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
		return (1);
	}
	return (1);
}

int	ft_rotate_both(t_sort *sort)
{
	ft_rotate_a(sort);
	ft_rotate_b(sort);
	return (1);
}
