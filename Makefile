# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 21:42:29 by hyko              #+#    #+#              #
#    Updated: 2022/06/11 15:51:15 by hyko             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all :
	arch -x86_64 gcc -L./mlx -lmlx -framework OpenGL -framework AppKit so_long.c map.c

clean :
	rm -rf a.out