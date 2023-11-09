/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_target.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:26:49 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/09 13:02:46 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_determine_closest_b(t_sort *sort, t_stack *elem)
{
	t_stack	*temp_b;

	temp_b = sort->st_b;
	while (sort->st_b)
	{
		if (!elem->trgt)
		{
			if (sort->st_b->ind < elem->ind)
				elem->trgt = temp_b;
		}
		else
		{
			if (sort->st_b < elem->trgt->ind)
				elem->trgt = sort->st_b;
		}
		sort->st_b = sort->st_b->ptr;
	}
	sort->st_b = temp_b;
}

void	ft_determine_targets_b(t_sort *sort)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	t_stack	*target;
	t_stack	*lowest_b;

	lowest_b = ft_stack_lowest(sort->st_b);
	temp_a = sort->st_a;;
	while (sort->st_a)
	{
		if (sort->st_a->ind > lowest_b)
			sort->st_a->trgt = sort->st_b;
		else
			ft_determine_closest(sort, sort->st_a);
		sort->st_a = sort->st_a->ptr;
	}
	sort->st_a = temp_a;
}
