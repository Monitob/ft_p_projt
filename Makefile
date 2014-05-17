# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/08 03:41:04 by dfrayssi          #+#    #+#              #
#    Updated: 2014/05/17 23:36:53 by jbernabe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
		make -C libft
		make -C client
		make -C server

clean:
		make clean -C libft
		make clean -C client
		make clean -C server


fclean:
		make fclean -C libft
		make fclean -C client
		make fclean -C server

re: fclean all
