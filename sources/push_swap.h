/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 10:18:06 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/07 12:24:46 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* include libraries */
# include "../libraries/libft/libft.h"
# include <stdio.h>

# define ERR_MSG	"Error\n"
# define MALL_ERR	"Error\nThere was an error while creating the stack(s)"

# define INT_MAX	2147483647
# define INT_MIN	-2147483648

typedef struct s_stack
{
	int				i;
	struct s_stack	*ptr;
	int				index;
}	t_stack;

typedef struct s_sort
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**in;
	int		elem;
}	t_sort;

/* function definitions */

/* ft_check_arguments */
// checks whether there are arguments to be sorted
void		ft_check_arguments(int argc, char **argv, t_sort *sort);
// checks whether the arguments are valid
void		ft_check_input(t_sort *sort);
// checks if the input consists only of numbers
int			ft_check_nondigit(char *input);
// checks whether the number is bigger than the max int;
int			ft_check_max_int(char *input);
// checks for duplicates in the input
int			ft_check_duplicates(int i, t_sort *sort);

/* ft_prepare_str */
// prepares the string, creates the elements and counts the number of elements
void		ft_prepare_str(int argc, char **argv, t_sort *sort);
// creates a sinlge str and splits it up into its single elements (based on ' ')
void		ft_str_creation(int argc, char **argv, t_sort *sort);
// checks whether the allocation of strings was successful
void		ft_check_alloc(char *str, t_sort *sort);
// counts the number of elements in the array (i.e., the input elements)
void		ft_num_elem(t_sort *sort);

/* ft_create_stack */
// creates the a stack; if something goes wrong, it quits the program
void		ft_create_stack(t_sort *sort);
// creates a stack element and adds it to the end of the stack
int			ft_create_stack_elem(char *value, t_stack **stack);
// determines the last element of the stack
t_stack		*ft_stack_last(t_stack **stack);

/* swap */
// changes the first two elems of stack a or does nothing if not enough elems
void	ft_swap_a(t_sort *sort, int print);
// changes the first two elems of stack b or does nothing if not enough elems
void	ft_swap_b(t_sort *sort, int print);
// see above; swaps first elems of both stacks - stack a and b
void	ft_swap_both(t_sort *sort);

/* push */
// first element of b is pushed to stack a; if there is no elem, it does nothing
void	ft_push_a(t_sort *sort);
// first element of a is pushed to stack b; if there is no elem, it does nothing
void	ft_push_b(t_sort *sort);

/* rotate */
// first element of a becomes the last, all other elements move one position up
void	ft_rotate_a(t_sort *sort, int print);
//


/* ft_quit */
// removes allocated memory and closes the program
void		ft_quit(t_sort *sort);
// removes all allocated elements from the stack and frees their memory
void		ft_clean_stack(t_stack *ptr);
// cleans the stack (frees and removes the stack elements)
void		ft_clean_stack(t_stack *stack);

/* utils */
// initites the struct, setting all the values to zero
void		ft_init_sort(t_sort *sort);
// converts a string to a long int
long int	ft_atoil(const char *nptr);

#endif
