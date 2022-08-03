# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarks <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 13:52:10 by jmarks            #+#    #+#              #
#    Updated: 2022/08/03 17:52:20 by jmarks           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=pipex.c \
	parse.c \
	utils.c \
	
OBJS=$(SRCS:.c=.o)

CC=gcc

CFLAGS=-Wall -Wextra -Werror

NAME=pipex

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) re -C ./libft
	cp libft/libft.a $(NAME)
	 $(CC) $(CLFAGS) -o $(NAME) $(OBJS) ./libft
	
%.o: %.c
		$(CC) -c $(CFLAGS) -o $@ $<

clean:
		$(MAKE) clean -C ./libft
		rm -f $(OBJS)

fclean:	clean
		$(MAKE) fclean -C ./libft
		rm -f $(NAME)

re:	fclean all

.PHONY:	all	clean fclean re
