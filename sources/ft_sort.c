/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:49:25 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/09 13:33:06 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_mini_sort(t_sort *sort)
{

}

void	ft_sort(t_sort *sort)
{
	if (ft_check_order(sort))
		ft_quit(sort);
	if (ft_check_reverse_order(sort))
	{
		while (!ft_check_order(sort))
			ft_rotate_a(sort, 1);
	}
	if (sort->elem == 3)
		ft_mini_sort(sort);
	// ft_sort_alg(sort);
}
