/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 10:49:10 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/06 16:14:16 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_in(char	**in)
{
	int	j;

	j = 0;
	while (in[j])
		free(in[j++]);
	free (in);
}

void	ft_clean_stack(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (stack)
	{
		temp = stack->ptr;
		free (stack);
		stack = temp;
	}
	ft_putstr_fd(MALL_ERR, 2);
}

void	ft_quit(t_sort *sort)
{
	if (sort->stack_a)
		ft_clean_stack(sort->stack_a);
	if (sort->stack_b)
		ft_clean_stack(sort->stack_b);
	if (sort->in)
		ft_free_in(sort->in);
	exit (0);
}
