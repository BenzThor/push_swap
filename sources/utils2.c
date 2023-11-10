/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:27:59 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/10 12:47:04 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a_to_b(t_sort *sort)
{
	t_stack	*push_elem;

	ft_stack_elements_both(sort);
	ft_determine_cost_both(sort);
	push_elem = ft_find_element(sort->st_a, sort->elem_a, sort->elem_b);
	ft_rotate_together(ft_hlvd_costs(push_elem, push_elem->trgt), \
						push_elem->a_md, sort);
	ft_rotate_elem(push_elem, sort, 1);
	ft_rotate_elem(push_elem->trgt, sort, 2);
	ft_push_a(sort);
}

void	ft_push_b_to_a(t_sort *sort)
{
	t_stack	*push_elem;

	ft_stack_elements_both(sort);
	ft_determine_cost_both(sort);
	push_elem = ft_find_element(sort->st_b, sort->elem_b, sort->elem_a);
	ft_rotate_together(ft_hlvd_costs(push_elem, push_elem->trgt), \
						push_elem->a_md, sort);
	ft_rotate_elem(push_elem, sort, 2);
	ft_rotate_elem(push_elem->trgt, sort, 1);
	ft_push_b(sort);
}

void	ft_rotate_elem(t_stack *elem, t_sort *sort, int stack)
{
	ft_stack_elements_both(sort);
	if (elem->st_pos != 1)
	{
		while (elem->st_pos != 1)
		{
			if (stack == 1 && elem->a_md == 1)
				ft_rotate_a(sort, 1);
			else if (stack == 1 && elem->a_md == 0)
				ft_reverse_rotate_a(sort, 1);
			else if (stack == 2 && elem->a_md == 1)
				ft_rotate_b(sort, 1);
			else
				ft_reverse_rotate_b(sort, 1);
			ft_stack_elements_both(sort);
		}
	}
}

void	ft_rotate_together(int rotations, int direction, t_sort *sort)
{
	while (rotations > 0)
	{
		if (direction == 1)
			ft_rotate_both(sort);
		else
			ft_reverse_rotate_both(sort);
		rotations--;
	}
}

t_stack	*ft_find_element(t_stack *stack, int s_elem, int t_elem)
{
	int		costs;
	t_stack	*temp;
	t_stack	*temp2;

	temp = stack;
	costs = ft_determine_comb_cost(stack, s_elem, t_elem);
	while (temp && stack->comb_cost != costs)
		temp = temp->ptr;
	return (temp);
}
