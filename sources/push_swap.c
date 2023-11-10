/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 10:41:38 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/10 18:16:33 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_sort	sort;

	ft_init_sort(&sort);
	ft_check_arguments(argc, argv, &sort);
	ft_create_stack(&sort);
	ft_index_stack(&sort);
	ft_sort(&sort);
}
