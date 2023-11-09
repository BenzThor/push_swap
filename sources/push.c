/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:53:30 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/09 12:11:04 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_sort *sort)
{
	t_stack	*temp;

	if (sort->st_b)
	{
		temp = sort->st_b;
		sort->st_b = sort->st_b->ptr;
		if (!sort->st_a)
		{
			sort->st_a = temp;
			sort->st_a->ptr = NULL;
		}
		else
		{
			temp->ptr = sort->st_a->ptr;
			sort->st_a = temp;
		}
	}
	ft_putstr_fd("pa\n", 1);
}

void	ft_push_b(t_sort *sort)
{
	t_stack	*temp;

	if (sort->st_a)
	{
		temp = sort->st_a;
		sort->st_a = sort->st_a->ptr;
		if (!sort->st_b)
		{
			sort->st_b = temp;
			sort->st_b->ptr = NULL;
		}
		else
		{
			temp->ptr = sort->st_b;
			sort->st_b = temp;
		}
	}
	ft_putstr_fd("pb\n", 1);
}
