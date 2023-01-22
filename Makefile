# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 14:40:37 by lbaumann          #+#    #+#              #
#    Updated: 2023/01/20 14:51:49 by lbaumann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft
LIBFT_A = libft/libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = stack_operations.c
T_SRCS = test.c

OBJS = ${SRCS:.c=.o}
T_OBJS = ${T_SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	cp $(LIBFT_A) $(NAME)
	ar -cr $(NAME) $(OBJS)
	
$(LIBFT_A):
	$(MAKE) -C $(LIBFT)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft

re: fclean all

test: $(T_OBJS) $(OBJS)
	cc $(T_OBJS) $(OBJS) -o test
	./test

.PHONY: all clean fclean re test
