# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 21:42:29 by hyko              #+#    #+#              #
#    Updated: 2022/06/16 06:34:54 by hyko             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ./src/so_long.c ./src/so_long_utils.c ./src/map.c ./src/key.c ./src/ft_split.c ./src/get_next_line.c ./src/get_next_line_utils.c 

all :
	arch -x86_64 cc -Wall -Wextra -Werror -L./mlx -lmlx -framework OpenGL -framework AppKit ./include/so_long.h $(SRCS)

clean :
	rm -rf a.out so_long.h.gch