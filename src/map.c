/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:03:14 by hyko              #+#    #+#             */
/*   Updated: 2022/06/16 16:58:43 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	map_check_size(t_map *map)
{
	int	i;

	i = 0;
	map->wid = ft_strlen(map->str[0]);
	while (map->str[i] != NULL)
	{
		if ((int)ft_strlen(map->str[i]) != map->wid)
			print_error_msg_2("ERROR\nmap must be rectangular\n");
		i++;
	}
	map->hei = i;
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
				print_error_msg_2("ERROR\nmap contain invalid character\n");
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
}

void	read_map(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	char	*str;
	char	*tmp;

	str = 0;
	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		print_error_msg_2("ERROR\nFailed To Open File\n");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		tmp = str;
		str = ft_strjoin(str, line);
		if (tmp != NULL)
			free(tmp);
		free(line);
	}
	map->str = ft_split(str, '\n');
	free(str);
	map_check(map);
}

void	map_check(t_map *map)
{
	map_check_size(map);
	map_check_wall(map);
	map_check_element(map);
	print_error_msg(map);
	if (map->error == -1)
		exit(0);
}
