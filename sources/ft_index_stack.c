/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:47:10 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/07 15:40:21 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index_stack(t_sort *sort)
{
	t_stack	*temp;
	t_stack	*element;
	int	index;

	temp = sort->stack_a;
	element = sort->stack_a;
	while (element)
	{
		index = 1;
		while (sort->stack_a)
		{
			if (element->i > sort->stack_a->i)
				index++;
			sort->stack_a = sort->stack_a->ptr;
		}
		element->index = index;
		element = element->ptr;
		sort->stack_a = temp;
	}
}
