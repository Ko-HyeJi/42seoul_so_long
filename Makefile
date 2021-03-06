# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 21:42:29 by hyko              #+#    #+#              #
#    Updated: 2022/06/19 17:55:30 by hyko             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
MLX = -L./mlx -lmlx -framework OpenGL -framework AppKit

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

SRC = $(addprefix ./src/, ft_split.c\
 get_next_line_utils.c\
 get_next_line.c\
 key.c\
 map.c\
 print_error.c\
 print_map.c\
 so_long_utils.c\
 so_long.c)

OBJ = $(SRC:.c=.o)

SRC_BN = $(addprefix ./bonus/, ft_split_bonus.c\
 get_next_line_bonus.c\
 get_next_line_utils_bonus.c\
 key_bonus.c\
 map_bonus.c\
 move_bonus.c\
 print_error_bonus.c\
 print_map_bonus.c\
 so_long_bonus.c\
 so_long_utils_bonus.c)

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