# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarks <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 15:08:41 by jmarks            #+#    #+#              #
#    Updated: 2022/08/03 10:16:49 by jmarks           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=ft_strlen.c \
	ft_strjoin.c \
	ft_split.c \
	ft_substr.c \
	ft_strncmp.c \
	ft_strchr.c	\


OBJS=$(SRCS:.c=.o)

CC=gcc

CFLAGS=-Wall -Wextra -Werror

NAME=libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	
%.o: %.c
		$(CC) -c $(CFLAGS) -o $@ $<

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re:	fclean all

.PHONY:	all	clean fclean re
