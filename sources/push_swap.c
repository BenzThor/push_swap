/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 10:41:38 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/09 12:10:42 by tbenz            ###   ########.fr       */
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
	printf("Stack A:\n");
	while (sort.st_a)
	{
		printf("Number: %d\t", sort.st_a->i);
		printf("Index: %d\n", sort.st_a->ind);
		sort.st_a = sort.st_a->ptr;
	}
	printf("Stack B:\n");
	while (sort.st_b)
	{
		printf("Number: %d\t", sort.st_b->i);
		printf("Index: %d\n", sort.st_b->ind);
		sort.st_b = sort.st_b->ptr;
	}
}
