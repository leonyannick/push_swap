# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 14:40:37 by lbaumann          #+#    #+#              #
#    Updated: 2023/01/27 23:41:37 by lbaumann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft
LIBFT_A = libft/libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = stack_operations.c push_swap.c push_pop.c insertion_sort.c radix_sort.c
T_SRCS = tests/test_push_pop.c

OBJS = ${SRCS:.c=.o}
T_OBJS = ${T_SRCS:.c=.o}

all: $(NAME)

$(NAME): $(LIBFT_A)
	gcc -g *.c -L. -lft -o $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT)
	mv $(LIBFT_A) .

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft

re: fclean all

test: $(T_OBJS) $(OBJS) $(LIBFT_A)
	cc $(T_OBJS) $(OBJS) -L. -lft -o test
	./test

.PHONY: all clean fclean re test
