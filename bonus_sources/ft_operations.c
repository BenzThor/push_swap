/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:53:25 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/12 12:50:58 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_exec_operations(char *str, t_sort *sort)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
		return (ft_swap_a(sort));
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		return (ft_swap_b(sort));
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		return (ft_swap_both(sort));
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		return (ft_push_a(sort));
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		return (ft_push_b(sort));
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		return (ft_rotate_a(sort));
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		return (ft_rotate_b(sort));
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		return (ft_rotate_both(sort));
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		return (ft_reverse_rotate_a(sort));
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		return (ft_reverse_rotate_b(sort));
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		return (ft_reverse_rotate_both(sort));
	else
		return (2);
}

void	ft_operations(t_sort *sort)
{
	char	*str;
	int		operations;

	str = get_next_line(0);
	if (!str)
		operations = 0;
	else
		operations = ft_exec_operations(str, sort);
	while (operations)
	{
		if (operations == 2)
			ft_quit(sort);
		str = get_next_line(0);
		if (!str)
			break;
		operations = ft_exec_operations(str, sort);
	}
}
