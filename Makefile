# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarks <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 13:52:10 by jmarks            #+#    #+#              #
#    Updated: 2022/08/04 14:07:52 by jmarks           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=pipex.c \
	parse.c \
	utils.c \
	
LIBFT=libft/libft.a

OBJS=$(SRCS:.c=.o)

CC=gcc

CFLAGS=-Wall -Wextra -Werror

NAME=pipex

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	 $(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	
$(LIBFT):
	$(MAKE) -C ./libft
	
%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(MAKE) clean -C ./libft
		rm -f $(OBJS)

fclean:	clean
		$(MAKE) fclean -C ./libft
		rm -f $(NAME)

re:	fclean all

.PHONY:	all	clean fclean re
