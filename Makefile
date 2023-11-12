# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 15:17:18 by tbenz             #+#    #+#              #
#    Updated: 2023/11/12 11:39:33 by tbenz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
NAME_BONUS		= checker

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

LIBFT 			= ./libraries/libft/libft.a

CC 				= cc

STANDARD_FLAGS 	= -Wall -Werror -Wextra -g

REMOVE 			= rm -f

SRCS_DIR		= ./sources/
BONUS_SRCS_DIR	= ./bonus_sources/

SRCS 			= $(addprefix $(SRCS_DIR),\
				push_swap.c \
				determine_cost.c \
				determine_target.c \
				ft_check_arguments.c \
				ft_create_stack.c \
				ft_prepare_str.c \
				ft_quit.c \
				ft_sort.c \
				push.c \
				reverse_rotate.c \
				rotate.c \
				sort_utils.c \
				stack_utils.c \
				swap.c \
				utils.c)


SRCS_BONUS 		= $(addprefix $(BONUS_SRCS_DIR),\
				checker.c \
				ft_check_arguments.c \
				ft_create_stack.c \
				ft_operations.c \
				ft_prepare_str.c \
				ft_quit.c \
				push.c \
				reverse_rotate.c \
				rotate.c \
				swap.c \
				utils.c)

all:			${LIBFT} ${NAME}

${NAME}:
				${CC} ${SRCS} ${LIBFT} ${STANDARD_FLAGS} -o ${NAME}
				@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"
				@echo

bonus:			${LIBFT} ${NAME_BONUS}

${NAME_BONUS}:
				${CC} ${SRCS_BONUS} ${LIBFT} ${STANDARD_FLAGS} -o ${NAME_BONUS}
				@echo "\n$(NAME): $(GREEN)$(NAME) was compiled with Bonus.$(RESET)"
				@echo

${LIBFT}:
				@echo
				make all -C libraries/libft

clean:
				make clean -C libraries/libft
				@echo

fclean:
				${REMOVE} ${NAME} ${NAME_BONUS}
				make fclean -C libraries/libft
				@echo "${NAME}: ${RED}${NAME}, ${NAME_BONUS} and libft.a were deleted${RESET}"
				@echo

re:				fclean all

rebonus:		fclean ${NAME_BONUS}

.PHONY:			all clean fclean re rebonus
