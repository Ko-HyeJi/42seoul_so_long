/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 21:42:35 by hyko              #+#    #+#             */
/*   Updated: 2022/06/14 21:32:58 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# define BUFFER_SIZE 100

#define X_EVENT_KEY_PRESS 2     // mlx_hook 함수의 두 번째 인자인 
#define X_EVENT_KEY_RELEASE 3   // x_event에 들어가는 값

#define KEY_W 13    // MacOS의 키보드 코드들이다.          
#define KEY_A 0     //
#define KEY_S 1     // 위에서 부터 차례대로
#define KEY_D 2     //
#define KEY_ESC 53  // 'W' 'A' 'S' 'D' 'ESC'들의 키보드 코드이다.

typedef struct s_img
{
	void	*empty;
	void	*wall;
	void	*player;
	void	*exit;
	void	*collectible;
}	t_img;

typedef struct s_map
{
	int		hei;
	int		wid;
	int		p;
	int		c;
	int		e;
	char	**str;
	int		error;
	int		x;
	int		y;
	void	*mlx;
	void	*win;
	t_img	*img;
}	t_map;

typedef	struct s_param
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

/* map.c */
void	print_error_msg(t_map *map);
void	map_check_size(t_map *map);
void	map_check_wall(t_map *map);
void	map_check_element(t_map *map);
void	read_map(char *filename, t_map *map);

/* so_long.c */
void	img_init(t_img *img, void *mlx);
void	map_init(t_map *map, t_img *img);
void	print_img(t_map *map);

/* so_long_utils.c */
char	*ft_strchr(const char *s, int c);

/* ft_split.c */
//size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
static char	**ft_malloc_error(char **str);
int			word_count(char const *s, char c);
int			word_len(char const *s, char c);
char		**ft_split(char const *s, char c);

/* key.c */
int		key_press(int keycode, t_map *map);
void	next_step(t_map *map);
void	next_img_c(t_map *map);

#endif