/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:25:42 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/06 17:52:24 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_sort *sort, int print)
{
	t_stack	*temp;

	if (sort->stack_a && sort->stack_a->ptr)
	{
		temp = sort->stack_a;
		sort->stack_a = sort->stack_a->ptr;
		temp->ptr = sort->stack_a->ptr;
		sort->stack_a->ptr = temp;
	}
	if (print == 1)
		ft_putstr_fd("sa\n", 1);
}

void	ft_swap_b(t_sort *sort, int print)
{
	t_stack	*temp;

	if (sort->stack_b && sort->stack_b->ptr)
	{
		temp = sort->stack_b;
		sort->stack_b = sort->stack_b->ptr;
		temp->ptr = sort->stack_b->ptr;
		sort->stack_b->ptr = temp;
	}
	if (print == 1)
		ft_putstr_fd("sb\n", 1);
}

void	ft_swap_both(t_sort *sort)
{
	ft_swap_a(sort, 0);
	ft_swap_b(sort, 0);
	ft_putstr_fd("ss\n", 1);
}
