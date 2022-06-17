/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 21:42:35 by hyko              #+#    #+#             */
/*   Updated: 2022/06/17 16:32:05 by hyko             ###   ########.fr       */
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

typedef struct s_location
{
	int	x;
	int	y;
}	t_location;

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
	int		e_direction;
}	t_img;

typedef struct s_map
{
	t_img	*img;
	void	*mlx;
	void	*win;
	char	**str;
	int		hei;
	int		wid;
	int		p;
	int		c;
	int		e;
	int		t;
	int		cnt;
	int		time;
}	t_map;

/* ft_split.c */
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
static char	**ft_malloc_error(char **str);
int			word_count(char const *s, char c);
int			word_len(char const *s, char c);
char		**ft_split(char const *s, char c);

/* get_next_line.c */
char		*get_next_line(int fd);
int			gnl_find_newline(char *read_line);
char		*gnl_read_line(int fd);
char		*gnl_expand_backup(char *backup, int fd);
char		*gnl_cut_backup(char *backup, char *return_line);

/* get_next_line_utils.c */
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const	*s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);

/* key.c */
int			key_press(int keycode, t_map *map);
void		find_player(t_map *map, t_location *player);
void		change_map(t_map *map, t_location *player, t_location *next);
int			click_red_cross(t_map *map);

/* map.c */
void		read_map(char *filename, t_map *map);
void		map_check(t_map *map);
void		map_check_size(t_map *map);
void		map_check_wall(t_map *map);
void		map_check_element(t_map *map);

/* move.c */
int			moving_img(t_map *map);
void		moving_collection(t_map *map);
void		find_enemy(t_map *map, t_location *enemy);
void		moving_enemy(t_map *map, t_location *enemy);

/* print_error.c */
void		check_element_error(t_map *map);
void		print_error_msg(char *str);

/* print_map.c */
void		print_map(t_map *map);
void		print_map_2(t_map *map, int w, int h);
void		print_step(t_map *map);
void		print_step_on_game(t_map *map);

/* so_long.c */
void		map_init(t_map *map, t_img *img);
void		img_init(t_img *img, void *mlx);

/* so_long_utils.c */
char		*ft_strchr(const char *s, int c);
void		ft_putstr(char *str);
int			nb_len(long nb);
char		*ft_itoa(int n);

#endif