/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:53:30 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/07 12:10:16 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_sort *sort)
{
	t_stack	*temp;

	if (sort->stack_b)
	{
		temp = sort->stack_b;
		sort->stack_b = sort->stack_b->ptr;
		if (!sort->stack_a)
		{
			sort->stack_a = temp;
			sort->stack_a->ptr = NULL;
		}
		else
		{
			temp->ptr = sort->stack_a->ptr;
			sort->stack_a = temp;
		}
	}
	ft_putstr_fd("pa\n", 1);
}

void	ft_push_b(t_sort *sort)
{
	t_stack	*temp;

	if (sort->stack_a)
	{
		temp = sort->stack_a;
		sort->stack_a = sort->stack_a->ptr;
		if (!sort->stack_b)
		{
			sort->stack_b = temp;
			sort->stack_b->ptr = NULL;
		}
		else
		{
			temp->ptr = sort->stack_b->ptr;
			sort->stack_b = temp;
		}
	}
	ft_putstr_fd("pb\n", 1);
}
