/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:25:42 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/12 11:23:28 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_swap_a(t_sort *sort)
{
	t_stack	*temp;

	if (sort->st_a && sort->st_a->ptr)
	{
		temp = sort->st_a;
		sort->st_a = sort->st_a->ptr;
		temp->ptr = sort->st_a->ptr;
		sort->st_a->ptr = temp;
		return (1);
	}
	return (1);
}

int	ft_swap_b(t_sort *sort)
{
	t_stack	*temp;

	if (sort->st_b && sort->st_b->ptr)
	{
		temp = sort->st_b;
		sort->st_b = sort->st_b->ptr;
		temp->ptr = sort->st_b->ptr;
		sort->st_b->ptr = temp;
		return (1);
	}
	return (1);
}

int	ft_swap_both(t_sort *sort)
{
	ft_swap_a(sort);
	ft_swap_b(sort);
	return (1);
}
