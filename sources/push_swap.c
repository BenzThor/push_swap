/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 10:41:38 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/07 13:41:51 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_sort	sort;

	ft_init_sort(&sort);
	ft_check_arguments(argc, argv, &sort);
	ft_create_stack(&sort);
	printf("Everything looks fine for now\n");
	ft_push_b(&sort);
	ft_push_b(&sort);
	ft_push_b(&sort);
	ft_push_b(&sort);
	ft_reverse_rotate_both(&sort);
	printf("Stack a\n");
	while (sort.stack_a)
	{
		printf("%d\n", sort.stack_a->i);
		sort.stack_a = sort.stack_a->ptr;
	}
	printf("Stack b\n");
	while (sort.stack_b)
	{
		printf("%d\n", sort.stack_b->i);
		sort.stack_b = sort.stack_b->ptr;
	}
}
