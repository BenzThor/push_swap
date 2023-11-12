/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:38:55 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/12 11:29:52 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_sort	sort;

	ft_init_sort(&sort);
	ft_check_arguments(argc, argv, &sort);
	ft_create_stack(&sort);
	ft_operations(&sort);
	ft_check_order_bonus(&sort);
}
