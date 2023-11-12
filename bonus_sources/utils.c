/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:57:33 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/12 11:32:21 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_init_sort(t_sort *sort)
{
	ft_bzero(sort, sizeof(t_sort));
}

long int	ft_atoil(const char *nptr)
{
	int			sign;
	long int	sum;

	sign = 1;
	while (*nptr == 32 || (*nptr > 8 && *nptr < 14))
		nptr++;
	if (*nptr == 43 || *nptr == 45)
	{
		if (*nptr == 45)
			sign *= -1;
		nptr++;
	}
	sum = 0;
	while (*nptr > 47 && *nptr < 58)
	{
		sum *= 10;
		sum += (*nptr - '0');
		nptr++;
	}
	return (sum * sign);
}

int	ft_check_order(t_sort *sort)
{
	t_stack	*temp;
	t_stack	*elem;

	temp = sort->st_a;
	elem = sort->st_a->ptr;
	while (sort->st_a)
	{
		while (elem)
		{
			if (sort->st_a->i > elem->i)
			{
				sort->st_a = temp;
				return (0);
			}
			elem = elem->ptr;
		}
		sort->st_a = sort->st_a->ptr;
		if (sort->st_a)
			elem = sort->st_a->ptr;
	}
	sort->st_a = temp;
	return (1);
}

void	ft_check_order_bonus(t_sort *sort)
{
	if (ft_check_order(sort) && sort->st_b == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}
