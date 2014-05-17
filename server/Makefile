# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/07 20:12:10 by jbernabe          #+#    #+#              #
#    Updated: 2014/05/17 03:58:46 by jbernabe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = ../serveur 

CFLAGS = -Wall -Wextra -Werror -I../libft

LIB = -L ../libft -lft

SRC = main.c

OBJ = $(@SRC:.c=.o)

all:	$(NAME)

$(NAME):  $(OBJ)
		@$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIB)

%o.:%.c
		@$(CC) $(SRC) $(CFLAGS) -c $<
		@echo  Compiling object : $<

clean:	
		@rm -f $(OBJ)

fclean : clean
		@rm -f $(NAME)

re :  fclean all

.PHONY: all
