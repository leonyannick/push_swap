# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 14:40:37 by lbaumann          #+#    #+#              #
#    Updated: 2023/02/14 12:20:48 by lbaumann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
B_NAME = checker

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCDIR = srcs/
INCDIR = includes/
OBJDIR = objs/
LIBDIR = srcs/libft/

#CFLAGS	+= -I $(INCDIR)$(HEADERS)

SRC = basic_stack_ops.c cost_sort_util.c create_chunks.c \
radix_sort.c insertion_sort.c specific_stack_ops2.c specific_stack_ops3.c \
utils1.c utils2.c input.c specific_stack_ops1.c cost_sort.c push_swap.c

B_SRC = basic_stack_ops.c cost_sort_util.c create_chunks.c \
radix_sort.c insertion_sort.c specific_stack_ops2.c specific_stack_ops3.c \
utils1.c utils2.c input.c specific_stack_ops1.c cost_sort.c checker.c

LIB = $(LIBDIR)libft.a
LIBINCL = -L$(LIBDIR) -lft

HEADERS = push_swap.h

SRCS := $(addprefix $(SRCDIR), $(SRC))
OBJ := $(SRC:.c=.o)
OBJS := $(addprefix $(OBJDIR), $(OBJ))

B_SRCS := $(addprefix $(SRCDIR), $(B_SRC))
B_OBJ := $(B_SRC:.c=.o)
B_OBJS := $(addprefix $(OBJDIR), $(B_OBJ))

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBINCL) -o $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB):
	$(MAKE) -C $(LIBDIR)

clean:
	rm -rf $(OBJDIR)
	$(MAKE) clean -C $(LIBDIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(B_NAME)
	$(MAKE) fclean -C $(LIBDIR)

re: fclean all
	
bonus: $(B_NAME)

$(B_NAME): $(LIB) $(B_OBJS)
	$(CC) $(CFLAGS) $(B_OBJS) $(LIBINCL) -o $(B_NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re test bonus
