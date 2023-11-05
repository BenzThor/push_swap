/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 10:18:06 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/05 13:09:16 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* include libraries */
# include "../libraries/libft/libft.h"
# include <stdio.h>

# define ERR_MSG	"Error\n"

# define INT_MAX	2147483647
# define INT_MIN	-2147483648

typedef struct s_stack
{
	int				i;
	struct s_stack	*ptr;
}	t_stack;

typedef struct s_sort
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_sort;

/* function definitions */

/* ft_check_arguments */

// checks whether there are arguments to be sorted
void	ft_check_arguments(int argc, char **argv, t_sort *sort);
// checks whether the arguments are valid
void	ft_check_input(int argc, char **argv, t_sort *sort);
// checks if the input consists only of numbers
int	ft_check_nondigit(char *input);
// checks whether the number is bigger than the max int;
int	ft_check_max_int(char *input);
// checks for duplicates in the input
int	ft_check_duplicates(char **argv, char *input, int i);

/* ft_quit */
// removes allocated memory and closes the program
void	ft_quit(t_sort *sort);
// removes all allocated elements from the stack and frees their memory
void	ft_clean_stack(t_stack *ptr);

/* utils */
// initites the struct, setting all the values to zero
void	ft_init_sort(t_sort *sort);
// converts a string to a long int
long int	ft_atoil(const char *nptr);

#endif
