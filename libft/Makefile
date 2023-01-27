# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 11:21:05 by lbaumann          #+#    #+#              #
#    Updated: 2023/01/24 16:27:53 by lbaumann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -c
NAME = libft.a
SRCS = ft_isdigit.c ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_toupper.c ft_tolower.c ft_strlen.c ft_bzero.c ft_memset.c ft_memcpy.c \
ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_striteri.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c \
ft_printf.c ./parsers/parsers.c ./printers/printers.c ft_atol.c ft_strcmp.c \

SRCS_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	ar -cr $(NAME) $(OBJS)

bonus: $(OBJS) $(OBJS_BONUS)
	ar -cr $(NAME) $(OBJS) $(OBJS_BONUS)

#%.o: %.c
#	$(CC) $(CFLAGS) $<

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
