# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zbohdanc <zbohdanc@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/31 17:22:28 by zbohdanc          #+#    #+#              #
#    Updated: 2026/09/02 16:02:43 by zbohdanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		push_swap

CC =		cc
CFLAGS =	-Wall -Wextra -Werror -g

MAKE =		make

INC_DIR =	. $(LIB_DIR)

SRC =		./main.c \
			./parse_flags.c \
			./parse_numbers.c \
			./ps_atoi.c \
			./stack.c \
			./stack_manipulations.c \
			./operations_push.c \
			./operations_swap.c \
			./operations_rotate.c \
			./operations_rrotate.c \
			./operations_helper.c \
			./sorting.c \
			./sorting_helper.c \
			./insertion_sort.c \
			./small_sorting.c \
			./sort_two.c \
			./sort_three.c \
			./sort_four_five.c \
			./print_benchmark.c \
			./chunk_sort.c \
			./index_stack.c \
			./quick_sort.c \
			./small_sorting_b.c \
			./sort_two_b.c \
			./sort_three_b.c \
			./sort_four_five_b.c \
			./partition.c \
			./routing_a.c \
			./routing_b.c \
			./restore_stacks.c
OBJ =		$(SRC:.c=.o)

LIB =		ft
LIB_DIR =	libft

all: lib $(NAME)

lib:
	$(MAKE) -C $(LIB_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIB_DIR) -l$(LIB) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(addprefix -I,$(INC_DIR)) -c $< -o $@

clean:
	$(MAKE) -C $(LIB_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIB_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
