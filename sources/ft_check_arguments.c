/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 10:44:22 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/05 13:08:55 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_duplicates(char **argv, char *input, int i)
{
	int	j;
	int	len;

	len = ft_strlen(input);
	j = 0;
	while (++j < i)
	{
		if(ft_strncmp(argv[j], input, len) == 0)
			return (1);
	}
	return (0);
}

int	ft_check_max_int(char *input)
{
	long int	n;
	int			len;

	len = ft_strlen(input);
	if ((input[0] != '-' && len > 10) || (input[0] == '-' && len > 11))
		return (1);
	else if ((input[0] != '-' && len < 10) || (input[0] == '-' && len < 11))
		return (0);
	else
		n = ft_atoil(input);
		if (n > INT_MAX || n < INT_MIN)
			return (1);
		return (0);
}

int	ft_check_nondigit(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] < '0'  || input[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	ft_check_input(int argc, char **argv, t_sort *sort)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if(ft_check_nondigit(argv[i]) || ft_check_max_int(argv[i]) ||
			ft_check_duplicates(argv, argv[i], i))
		{
			ft_putstr_fd(ERR_MSG, 2);
			ft_quit(sort);
		}
	}
}

void	ft_check_arguments(int argc, char **argv, t_sort *sort)
{
	if (argc < 2)
	 	ft_quit(sort);
	else
		ft_check_input(argc, argv, sort);
}
