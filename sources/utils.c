/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:57:33 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/05 12:56:30 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
