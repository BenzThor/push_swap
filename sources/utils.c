/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:57:33 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/09 12:09:09 by tbenz            ###   ########.fr       */
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

	temp = sort->st_a;
	element = sort->st_a;
	while (element)
	{
		index = 1;
		while (sort->st_a)
		{
			if (element->i > sort->st_a->i)
				index++;
			sort->st_a = sort->st_a->ptr;
		}
		element->ind = index;
		element = element->ptr;
		sort->st_a = temp;
	}
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

int	ft_check_reverse_order(t_sort *sort)
{
	t_stack	*temp;
	t_stack	*elem;

	temp = sort->st_a;
	elem = sort->st_a->ptr;
	while (sort->st_a)
	{
		while (elem)
		{
			if (sort->st_a->i < elem->i)
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
