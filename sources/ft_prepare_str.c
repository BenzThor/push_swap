/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:38:45 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/06 20:10:30 by tbenz            ###   ########.fr       */
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

char	*ft_strjoin_ps(char **s1, char *s2, t_sort *sort)
{
	size_t	len;
	char	*jstr;

	if (!*s1)
	{
		*s1 = (char *)malloc(sizeof(char));
		ft_check_alloc(*s1, sort);
		(*s1)[0] = '\0';
	}
	len = ft_strlen(*s1) + ft_strlen(s2) +1;
	jstr = malloc(len);
	if (jstr == NULL)
	{
		free (*s1);
		return (NULL);
	}
	ft_strlcpy(jstr, *s1, ft_strlen(*s1) + 1);
	ft_strlcat(jstr, s2, len);
	free(*s1);
	return (jstr);
}

void	ft_str_creation(int argc, char **argv, t_sort *sort)
{
	int		i;
	char	*str_compl;

	i = 0;
	str_compl = NULL;
	while (++i < argc)
	{
			str_compl = ft_strjoin_ps(&str_compl, " ", sort);
			ft_check_alloc(str_compl, sort);
			str_compl = ft_strjoin_ps(&str_compl, argv[i], sort);
			ft_check_alloc(str_compl, sort);
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
