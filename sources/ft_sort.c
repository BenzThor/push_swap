/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:49:25 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/09 17:56:07 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_a_to_b(t_sort *sort)
{
	ft_stack_elements(sort->st_a);
	ft_stack_elements(sort->st_b);
	ft_determine_cost(sort->st_a);
	ft_determine_cost(sort->st_b);
	ft_determine_comb_cost(sort);
}

void	ft_mini_sort(t_sort *sort)
{
	ft_stack_elements(sort->st_a);
	if (ft_stack_highest(sort->st_a)->stack_pos != 3)
	{
		if (ft_stack_highest(sort->st_a)->stack_pos == 2)
			ft_reverse_rotate_a(sort, 1);
		else if (ft_stack_highest(sort->st_a)->stack_pos == 1)
			ft_rotate_a(sort, 1);
	}
	if (!ft_check_order(sort))
		ft_swap_a(sort, 1);
}

void	ft_mini_sort4(t_sort *sort)
{
	while(ft_stack_lowest(sort->st_a)->stack_pos != 1)
	{
		if (ft_stack_lowest(sort->st_a)->stack_pos > (sort->elem / 2))
			ft_reverse_rotate_a(sort, 1);
		else
			ft_rotate_a(sort, 1);
		ft_stack_elements(sort->st_a);
	}
	ft_push_b(sort);
	ft_mini_sort(sort);
	ft_push_a(sort);
}

void	ft_sort(t_sort *sort)
{
	if (ft_check_order(sort))
		ft_quit(sort);
	if (sort->elem == 3)
		ft_mini_sort(sort);
	if (sort->elem == 4)
		ft_mini_sort4(sort);
	if (sort->elem > 4)
	{
		ft_push_b(sort);
		ft_push_b(sort);
		ft_stack_elements(sort->st_b);
		if (ft_stack_lowest(sort->st_b)->stack_pos == 1)
			ft_swap_b(sort, 1);
		while (ft_stack_elements(sort->st_a) > 3)
			ft_a_to_b(sort);
	}
}
