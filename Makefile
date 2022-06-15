# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 21:42:29 by hyko              #+#    #+#              #
#    Updated: 2022/06/16 02:10:23 by hyko             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = so_long.c so_long_utils.c map.c key.c ft_split.c get_next_line.c get_next_line_utils.c 

all :
	arch -x86_64 cc -Wall -Wextra -Werror -L./mlx -lmlx -framework OpenGL -framework AppKit so_long.h $(SRCS)

clean :
	rm -rf a.out so_long.h.gch