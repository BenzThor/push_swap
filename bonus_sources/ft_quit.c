/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 10:49:10 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/12 11:21:18 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	ft_putstr_fd("Error\n", 2);
	exit (0);
}
