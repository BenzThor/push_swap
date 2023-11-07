/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:57:33 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/07 15:45:45 by tbenz            ###   ########.fr       */
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

void	ft_index_stack(t_sort *sort)
{
	t_stack	*temp;
	t_stack	*element;
	int		index;

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
