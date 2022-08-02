# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarks <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 13:52:10 by jmarks            #+#    #+#              #
#    Updated: 2022/08/02 18:04:34 by jmarks           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

CFLAGS= -Wall -Wextra -Werror

NAME = pipex

INCLUDE = inc, libft
LIBFT_PATH = libft
SRC_PATH = src
OBJ_PATH = objs

SOURCES = parse.c \
	utils.c \
	pipex.c \

SRC = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -sC $(LIBFT_PATH) 
	$(CC) $(CFLAGS) -L $(LIBFT_PATH) -o $@ $^ -lft
	
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INCLUDE)/$(NAME).h
		mkdir -p objs
		$(CC) $(CFLAGS) -I$(INCLUDE) -c -o $@ $<

clean:
		$(MAKE) clean -sC $(LIBFT_PATH)
		rm -f $(OBJ_PATH)

fclean:	clean
		$(MAKE) fclean -sC $(LIBFT_PATH)
		rm -f $(NAME)

re:	fclean all

.PHONY:	all	clean fclean re
