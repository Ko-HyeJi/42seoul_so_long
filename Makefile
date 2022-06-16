# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyko <hyko@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 21:42:29 by hyko              #+#    #+#              #
#    Updated: 2022/06/16 17:03:21 by hyko             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BONUS = so_long_bonus

CC = cc
CFLAG = -Wall -Wextra -Werror
RM = rm -rf
MLX = -L./mlx -lmlx -framework OpenGL -framework AppKit

INCLUDE = ./include/so_long.h
INCLUDE_BN = ./include/so_long_bonus.h

SRC = ./src/so_long.c\
 ./src/so_long_utils.c\
 ./src/map.c\
 ./src/key.c\
 ./src/error.c\
 ./src/ft_split.c\
 ./src/get_next_line.c\
 ./src/get_next_line_utils.c 

SRC_BN = ./bonus/so_long_bonus.c\
 ./bonus/so_long_utils_bonus.c\
 ./bonus/map_bonus.c\
 ./bonus/key_bonus.c\
 ./bonus/ft_split_bonus.c\
 ./bonus/get_next_line_bonus.c\
 ./bonus/get_next_line_utils_bonus.c\
 ./bonus/moving_bonus.c

all :
	$(CC) $(CFLAG) $(MLX) $(INCLUDE) $(SRC)

bonus : 
	$(CC) $(CFLAG) $(MLX) $(INCLUDE_BN) $(SRC_BN) 

clean :
	rm -rf a.out so_long.h.gch

fclean :

re : 

.PHONY : all bonus clean fclean re