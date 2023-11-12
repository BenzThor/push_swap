/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 10:44:22 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/12 11:59:51 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_check_duplicates(int i, t_sort *sort)
{
	int		j;
	int		len;
	char	*input;

	input = sort->in[i];
	len = ft_strlen(input);
	j = -1;
	while (++j < i)
	{
		if (ft_strlen(input) > ft_strlen(sort->in[j]))
			len = ft_strlen(input);
		else
			len = ft_strlen(sort->in[j]);
		if (ft_strncmp(sort->in[j], input, len) == 0)
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
	{
		n = ft_atoil(input);
		if (n > INT_MAX || n < INT_MIN)
			return (1);
		return (0);
	}
}

int	ft_check_nondigit(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if ((i == 0 && input[0] == '-' && input[1] != '\0')
			|| (input[i] >= '0' && input[i] <= '9'))
			i++;
		else
			return (1);
	}
	return (0);
}

void	ft_check_input(t_sort *sort)
{
	int	i;

	i = -1;
	while (++i < sort->elem)
	{
		if (ft_check_nondigit(sort->in[i]) || ft_check_max_int(sort->in[i])
			|| ft_check_duplicates(i, sort))
			ft_quit(sort);
	}
}

void	ft_check_arguments(int argc, char **argv, t_sort *sort)
{
	if (argc < 2)
		ft_quit(sort);
	else
	{
		ft_prepare_str(argc, argv, sort);
		if (sort->elem < 2)
			ft_quit(sort);
		ft_check_input(sort);
	}
}
