# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 21:42:29 by hyko              #+#    #+#              #
#    Updated: 2022/06/17 13:06:55 by hyko             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAG = -Wall -Wextra -Werror
RM = rm -rf
MLX = -L./mlx -lmlx -framework OpenGL -framework AppKit

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

SRC = $(addprefix ./src/, so_long.c\
 so_long_utils.c\
 map.c\
 key.c\
 print_map.c\
 print_error.c\
 ft_split.c\
 get_next_line.c\
 get_next_line_utils.c)

OBJ = $(SRC:.c=.o)

SRC_BN = $(addprefix ./bonus/, so_long_bonus.c\
 so_long_utils_bonus.c\
 map_bonus.c\
 key_bonus.c\
 ft_split_bonus.c\
 get_next_line_bonus.c\
 get_next_line_utils_bonus.c\
 moving_bonus.c)

OBJ_BN = $(SRC_BN:.c=.o)

ifdef MAKE_BONUS
	OBJS = $(OBJ_BN)
else
	OBJS = $(OBJ)
endif

all : $(NAME)
	
bonus :
	$(MAKE) MAKE_BONUS=1 all
	
$(NAME) : $(OBJS)
	make -C ./mlx/
	$(CC) $(CFLAG) $(MLX) -o $@ $^
	
clean :
	make -C ./mlx/ clean
	$(RM) $(OBJ) $(OBJ_BN)

fclean : clean
	$(RM) $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all bonus clean fclean re