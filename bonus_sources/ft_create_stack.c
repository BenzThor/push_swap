/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:35:20 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/12 10:49:19 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack	*ft_stack_last(t_stack **stack)
{
	t_stack	*stack_last;

	stack_last = *stack;
	while (stack_last->ptr)
		stack_last = stack_last->ptr;
	return (stack_last);
}

int	ft_create_stack_elem(char *value, t_stack **stack)
{
	t_stack	*stack_elem;
	t_stack	*stack_last;

	stack_elem = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_elem)
		return (0);
	stack_elem->i = ft_atoi(value);
	stack_elem->ptr = NULL;
	if (!*stack)
		*stack = stack_elem;
	else
	{
		stack_last = ft_stack_last(stack);
		stack_last->ptr = stack_elem;
	}
	return (1);
}

void	ft_create_stack(t_sort *sort)
{
	int	i;

	i = -1;
	while (++i < sort->elem)
	{
		if (!ft_create_stack_elem(sort->in[i], &(sort->st_a)))
			ft_quit(sort);
	}
}
