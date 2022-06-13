# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 21:42:29 by hyko              #+#    #+#              #
#    Updated: 2022/06/13 15:42:40 by hyko             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = so_long.c so_long_utils.c map.c ft_split.c get_next_line.c get_next_line_utils.c

all :
	arch -x86_64 gcc -L./mlx -lmlx -framework OpenGL -framework AppKit so_long.h $(SRCS)

clean :
	rm -rf a.out