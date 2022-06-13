/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 21:42:35 by hyko              #+#    #+#             */
/*   Updated: 2022/06/13 21:37:38 by hyko             ###   ########.fr       */
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

typedef struct s_map
{
	int		hei;
	int		wid;
	int		p;
	int		c;
	int		e;
	char	**str;
	int		error;
}	t_map;

typedef struct s_img
{
	void	*empty;
	void	*wall;
	void	*player;
	void	*exit;
	void	*collectible;
}	t_img;

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
t_map	print_error_msg(t_map map);
t_map	map_check_size(t_map map);
t_map	map_check_wall(t_map map);
t_map	map_check_element(t_map map);
t_map	read_map(char *filename, t_map map);

/* so_long.c */
t_map	map_init(void);

/* so_long_utils.c */
char	*ft_strchr(const char *s, int c);

/* ft_split.c */
//size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
static char	**ft_malloc_error(char **str);
int			word_count(char const *s, char c);
int			word_len(char const *s, char c);
char		**ft_split(char const *s, char c);

#endif