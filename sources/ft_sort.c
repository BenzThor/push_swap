/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:49:25 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/07 16:16:23 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_order(t_sort *sort)
{
	t_stack	*temp;
	t_stack	*elem;

	temp = sort->stack_a;
	elem = sort->stack_a->ptr;
	while (sort->stack_a)
	{
		while (elem)
		{
			if (sort->stack_a->i > elem->i)
			{
				sort->stack_a = temp;
				return (0);
			}
			elem = elem->ptr;
		}
		sort->stack_a = sort->stack_a->ptr;
		if (sort->stack_a)
			elem = sort->stack_a->ptr;
	}
	sort->stack_a = temp;
	return (1);
}

int	ft_check_reverse_order(t_sort *sort)
{
	t_stack	*temp;
	t_stack	*elem;

	temp = sort->stack_a;
	elem = sort->stack_a->ptr;
	while (sort->stack_a)
	{
		while (elem)
		{
			if (sort->stack_a->i < elem->i)
			{
				sort->stack_a = temp;
				return (0);
			}
			elem = elem->ptr;
		}
		sort->stack_a = sort->stack_a->ptr;
		if (sort->stack_a)
			elem = sort->stack_a->ptr;
	}
	sort->stack_a = temp;
	return (1);
}

void	ft_sort(t_sort *sort)
{
	if (ft_check_order(sort))
		printf("Already sorted");
	if (ft_check_reverse_order(sort))
		printf("Already reverse sorted");
}
