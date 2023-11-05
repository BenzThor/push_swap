/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 10:49:10 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/05 12:30:49 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clean_stack(t_stack *ptr)
{
	// should remove allocated elements and free their memory

	int	i;

	i = 0;
}

void	ft_quit(t_sort *sort)
{
	if (sort->stack_a)
		ft_clean_stack(sort->stack_a);
	if (sort->stack_b)
		ft_clean_stack(sort->stack_b);
	exit (0);
}
