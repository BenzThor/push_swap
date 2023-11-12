/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 10:18:06 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/12 12:48:06 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

/* include libraries */
# include "../libraries/libft/libft.h"
# include <stdio.h>

/* error messages */
# define ERR_MSG	"Error\n"
# define MALL_ERR	"Error\nThere was an error while creating the stack(s)"

/* max INT & min INT */
# define INT_MAX	2147483647
# define INT_MIN	-2147483648

/* stack struct, saving information of single struct elements */
typedef struct s_stack
{
	int				i;
	struct s_stack	*ptr;
}	t_stack;

/* sort struct, storing the two stacks, number of elems and the input */
typedef struct s_sort
{
	t_stack	*st_a;
	t_stack	*st_b;
	char	**in;
	int		elem;
	int		elem_a;
	int		elem_b;
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

/* ft_operations */
// gets the operations from the input stream and checks whether it is valid inp
void		ft_operations(t_sort *sort);
// checks the input for validity and if so, executes the commands
int			ft_exec_operations(char *str, t_sort *sort);

/* swap */
// changes the first two elems of stack a or does nothing if not enough elems
int			ft_swap_a(t_sort *sort);
// changes the first two elems of stack b or does nothing if not enough elems
int			ft_swap_b(t_sort *sort);
// see above; swaps first elems of both stacks - stack a and b
int			ft_swap_both(t_sort *sort);

/* push */
// first element of b is pushed to stack a; if there is no elem, it does nothing
int			ft_push_a(t_sort *sort);
// first element of a is pushed to stack b; if there is no elem, it does nothing
int			ft_push_b(t_sort *sort);

/* rotate */
// first element of a becomes the last, all other elements move one position up
int			ft_rotate_a(t_sort *sort);
// first element of b becomes the last, all other elements move one position up
int			ft_rotate_b(t_sort *sort);
// rotates both, stack a and b
int			ft_rotate_both(t_sort *sort);

/* reverse rotate */
// shifts down all elements of a by 1. The last element becomes the first one
int			ft_reverse_rotate_a(t_sort *sort);
// shifts down all elements of b by 1. The last element becomes the first one
int			ft_reverse_rotate_b(t_sort *sort);
//	shifts down both stacks by 1. The last element becomes the first one
int			ft_reverse_rotate_both(t_sort *sort);
// determines the second last element and returns a pointer to this element
t_stack		*ft_stack_second_last(t_stack **st_add, t_stack **last_address);

/* utils */
// initites the struct, setting all the values to zero
void		ft_init_sort(t_sort *sort);
// converts a string to a long int
long int	ft_atoil(const char *nptr);
// checks, whether the input is in order
int			ft_check_order(t_sort *sort);
// checks the order and if st b is empty and if so returns "OK" otherwise "KO"
void		ft_check_order_bonus(t_sort *sort);

/* ft_quit */
// removes allocated memory and closes the program
void		ft_quit(t_sort *sort);
// removes all allocated elements from the stack and frees their memory
void		ft_clean_stack(t_stack *ptr);
// cleans the stack (frees and removes the stack elements)
void		ft_clean_stack(t_stack *stack);

#endif
