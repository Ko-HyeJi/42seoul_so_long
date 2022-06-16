/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 21:42:35 by hyko              #+#    #+#             */
/*   Updated: 2022/06/16 15:01:51 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define BUFFER_SIZE 100

# define KEY_PRESS 2
# define RED_CROSS 17

# define KEY_W 13
# define KEY_A 0 
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

typedef struct s_img
{
	void	*empty;
	void	*wall;
	void	*player_r;
	void	*player_l;
	void	*exit;
	void	*collection_r;
	void	*collection_l;
	void	*enemy;
	int		p_direction;
	int		c_direction;
}	t_img;

typedef struct s_map
{
	int		hei;
	int		wid;
	int		p;
	int		c;
	int		e;
	int		t;
	char	**str;
	int		error;
	int		x;
	int		y;
	int		cnt;
	void	*mlx;
	void	*win;
	t_img	*img;
}	t_map;

typedef struct s_param
{
	int	x;
	int	y;
}	t_param;

/* get_next_line.c */
char	*get_next_line(int fd);
char	*gnl_expand_backup(char *backup, int fd);
char	*gnl_cut_backup(char *backup, char *return_line);
char	*gnl_read_line(int fd);
int		gnl_find_newline(char *read_line);

/* get_next_line_utils.c */
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const	*s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

/* ft_split.c */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		word_count(char const *s, char c);
int		word_len(char const *s, char c);
char	**ft_split(char const *s, char c);

/* map.c */
void	print_error_msg(t_map *map);
void	map_check_size(t_map *map);
void	map_check_wall(t_map *map);
void	map_check_element(t_map *map);
void	read_map(char *filename, t_map *map);

/* key.c */
int		key_press(int keycode, t_map *map);
void	change_map(t_map *map, t_param *next);
int		click_red_cross(t_map *map);

/* so_long.c */
void	img_init(t_img *img, void *mlx);
void	map_init(t_map *map, t_img *img);
void	print_img(t_map *map);

/* so_long_utils.c */
char	*ft_strchr(const char *s, int c);
void	ft_putstr(char *str);
char	*ft_itoa(int n);

/* enemy_bonus.c */
int	moving_enemy(t_map *map);

#endif