/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:03:14 by hyko              #+#    #+#             */
/*   Updated: 2022/06/16 12:17:05 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_error_msg(t_map *map)
{
	if (map->c < 1 || map->p != 1 || map->e != 1)
		map->error = -3;
	if (map->c == 0)
		ft_putstr("ERROR\nneed more collection\n");
	if (map->p == 0)
		ft_putstr("ERROR\nneed a player\n");
	if (map->e == 0)
		ft_putstr("ERROR\nneed an exit\n");
	if (map->p > 1)
		ft_putstr("ERROR\ntoo many players\n");
	if (map->e > 1)
		ft_putstr("ERROR\ntoo many exits\n");
}

void	map_check_size(t_map *map)
{
	int	i;

	i = 0;
	map->wid = ft_strlen(map->str[0]);
	while (map->str[i] != NULL)
	{
		if ((int)ft_strlen(map->str[i]) != map->wid)
			map->error = -1;
		i++;
	}
	map->hei = i;
	if (map->error == -1)
		ft_putstr("ERROR\nmap must be rectangular\n");
}

void	map_check_wall(t_map *map)
{
	int	h;
	int	w;

	h = 0;
	while (h < map->hei)
	{
		w = 0;
		while (w < map->wid)
		{
			if (h == 0 || h == map->hei - 1)
			{
				if (map->str[h][w] != '1')
					map->error = -2;
			}
			else if (w == 0 || w == map->wid - 1)
			{
				if (map->str[h][w] != '1')
					map->error = -2;
			}
			w++;
		}
		h++;
	}
	if (map->error == -2)
		ft_putstr("ERROR\nmap must be closed by by walls\n");
}

void	map_check_element(t_map *map)
{
	int	h;
	int	w;

	h = 0;
	while (h < map->hei)
	{
		w = 0;
		while (w < map->wid)
		{
			if (ft_strchr("01PEC", map->str[h][w]) == NULL)
				map->error = -4;
			else if (map->str[h][w] == 'P')
			{
				map->p++;
				map->x = w;
				map->y = h;
			}
			else if (map->str[h][w] == 'E')
				map->e++;
			else if (map->str[h][w] == 'C')
				map->c++;
			w++;
		}
		h++;
	}
	if (map->error == -4)
		ft_putstr("ERROR\nmap contain invalid character\n");
}

void	read_map(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	char	*str;

	str = "";
	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		ft_putstr("Failed To Open File\n");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		str = ft_strjoin(str, line);
	}
	map->str = ft_split(str, '\n');
	map_check_size(map);
	map_check_wall(map);
	map_check_element(map);
	print_error_msg(map);
}
