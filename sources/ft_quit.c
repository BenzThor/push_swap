/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 10:49:10 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/09 12:10:13 by tbenz            ###   ########.fr       */
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
}

void	ft_quit(t_sort *sort)
{
	if (sort->st_a)
		ft_clean_stack(sort->st_a);
	if (sort->st_b)
		ft_clean_stack(sort->st_b);
	if (sort->in)
		ft_free_in(sort->in);
	exit (0);
}
