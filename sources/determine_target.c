/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_target.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:26:49 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/10 15:45:15 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_determine_closest_b(t_sort *sort, t_stack *elm)
{
	t_stack	*temp_b;

	temp_b = sort->st_b;
	while (sort->st_b)
	{
		if (!elm->trgt)
		{
			if (sort->st_b->ind < elm->ind)
				elm->trgt = sort->st_b;
		}
		else
		{
			if (sort->st_b->ind < elm->ind && sort->st_b->ind > elm->trgt->ind)
				elm->trgt = sort->st_b;
		}
		sort->st_b = sort->st_b->ptr;
	}
	sort->st_b = temp_b;
}

void	ft_determine_targets_b(t_sort *sort)
{
	t_stack	*temp_a;

	ft_targets_init(sort);
	temp_a = sort->st_a;
	while (sort->st_a)
	{
		if (sort->st_a->ind < ft_stack_lowest(sort->st_b)->ind)
			sort->st_a->trgt = ft_stack_highest(sort->st_b);
		else
			ft_determine_closest_b(sort, sort->st_a);
		sort->st_a = sort->st_a->ptr;
	}
	sort->st_a = temp_a;
}

void	ft_determine_closest_a(t_sort *sort, t_stack *elm)
{
	t_stack	*temp_a;

	temp_a = sort->st_a;
	while (sort->st_a)
	{
		if (!elm->trgt)
		{
			if (sort->st_a->ind > elm->ind)
				elm->trgt = sort->st_a;
		}
		else
		{
			if (sort->st_a->ind > elm->ind && sort->st_a->ind < elm->trgt->ind)
				elm->trgt = sort->st_a;
		}
		sort->st_a = sort->st_a->ptr;
	}
	sort->st_a = temp_a;
}

void	ft_determine_targets_a(t_sort *sort)
{
	t_stack	*temp_b;

	ft_targets_init(sort);
	temp_b = sort->st_b;
	while (sort->st_b)
	{
		if (sort->st_b->ind > ft_stack_highest(sort->st_a)->ind)
			sort->st_b->trgt = ft_stack_lowest(sort->st_a);
		else
			ft_determine_closest_a(sort, sort->st_b);
		sort->st_b = sort->st_b->ptr;
	}
	sort->st_b = temp_b;
}

void	ft_targets_init(t_sort *sort)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = sort->st_a;
	temp_b = sort->st_b;
	while (temp_a)
	{
		if (temp_a->trgt)
			temp_a->trgt = NULL;
		temp_a = temp_a->ptr;
	}
	while (temp_b)
	{
		if (temp_b->trgt)
			temp_b->trgt = NULL;
		temp_b = temp_b->ptr;
	}
}
