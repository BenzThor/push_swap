/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 10:41:38 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/09 14:01:12 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_sort	sort;
	t_stack	*temp1;
	t_stack	*temp2;

	ft_init_sort(&sort);
	ft_check_arguments(argc, argv, &sort);
	ft_create_stack(&sort);
	ft_index_stack(&sort);
	// ft_sort(&sort);
	ft_push_b(&sort);
	ft_push_b(&sort);
	ft_push_b(&sort);
	ft_push_b(&sort);
	ft_determine_targets_b(&sort);
	temp1 = sort.st_a;
	temp2 = sort.st_b;
	printf("Stack A:\n");
	while (sort.st_a)
	{
		printf("Number: %d\t", sort.st_a->i);
		printf("Target Element Number: %d\n", sort.st_a->trgt->i);
		sort.st_a = sort.st_a->ptr;
	}
	printf("Stack B:\n");
	while (sort.st_b)
	{
		printf("Number: %d\t", sort.st_b->i);
		if (sort.st_b->trgt)
			printf("Target Element Number: %d\n", sort.st_b->trgt->i);
		sort.st_b = sort.st_b->ptr;
	}
	sort.st_a = temp1;
	sort.st_b = temp2;
	ft_determine_targets_a(&sort);
	while (sort.st_a)
	{
		printf("Number: %d\t", sort.st_a->i);
		printf("Target Element Number: %d\n", sort.st_a->trgt->i);
		sort.st_a = sort.st_a->ptr;
	}
	printf("Stack B:\n");
	while (sort.st_b)
	{
		printf("Number: %d\t", sort.st_b->i);
		printf("Target Element Number: %d\n", sort.st_b->trgt->i);
		sort.st_b = sort.st_b->ptr;
	}
	/* printf("Stack A:\n");
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
	} */
}
