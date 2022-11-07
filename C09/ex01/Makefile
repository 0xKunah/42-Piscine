# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/13 09:24:38 by dbiguene          #+#    #+#              #
#    Updated: 2022/08/15 11:44:11 by dbiguene         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

all: libft.a
	
libft.a:
	cd srcs && gcc -Wall -Wextra -Werror -c ../includes/ft.h ./ft_*.c && cd ../ && ar rc libft.a ./srcs/ft_*.o

clean:
	find . -type f \( -name "*.o" -o -name "*.gch" \) -delete

fclean: clean
	find . -type f -name "libft.a" -delete

re: fclean all
