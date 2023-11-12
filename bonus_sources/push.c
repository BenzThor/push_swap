/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:53:30 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/12 11:24:20 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_push_a(t_sort *sort)
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
			temp->ptr = sort->st_a;
			sort->st_a = temp;
		}
		return (1);
	}
	return (1);
}

int	ft_push_b(t_sort *sort)
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
		return (1);
	}
	return (1);
}
