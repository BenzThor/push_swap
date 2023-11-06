/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:38:45 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/06 17:19:07 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_num_elem(t_sort *sort)
{
	int	i;

	i = 0;
	while (sort->in[i])
		i++;
	sort->elem = i;
}

void	ft_check_alloc(char *str, t_sort *sort)
{
	if (!str)
		ft_quit(sort);
}

void	ft_str_creation2(char **argv, int *i, char **str, t_sort *sort)
{
		if (!(*str))
		{
			if (!argv[*i])
				(*i)++;
			else
			{
				*str = ft_strjoin("", argv[*i]);
				ft_check_alloc(*str, sort);
			}
		}
		else
		{
			if (!argv[*i])
				(*i)++;
			else
			{
				*str = ft_strjoin(*str, " ");
				ft_check_alloc(*str, sort);
				*str = ft_strjoin(*str, argv[*i]);
				ft_check_alloc(*str, sort);
			}
		}
}

void	ft_str_creation(int argc, char **argv, t_sort *sort)
{
	int		i;
	char	*str_compl;

	i = 0;
	while (++i < argc)
	{
		ft_str_creation2(argv, &i, &str_compl, sort);
	}
	sort->in = ft_split(str_compl, ' ');
	free(str_compl);
	if (!sort->in)
		ft_quit(sort);
}

void	ft_prepare_str(int argc, char **argv, t_sort *sort)
{
	ft_str_creation(argc, argv, sort);
	ft_num_elem(sort);
}
