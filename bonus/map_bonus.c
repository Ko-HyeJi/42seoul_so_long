/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:03:14 by hyko              #+#    #+#             */
/*   Updated: 2022/06/17 15:15:55 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	read_map(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	char	*str;
	char	*tmp;

	str = 0;
	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		print_error_msg("ERROR\nfailed to open file\n");
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
}

void	map_check_size(t_map *map)
{
	int	i;

	i = 0;
	map->wid = ft_strlen(map->str[0]);
	while (map->str[i] != NULL)
	{
		if ((int)ft_strlen(map->str[i]) != map->wid)
			print_error_msg("ERROR\nmap must be rectangular\n");
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
					print_error_msg("ERROR\nmap must be closed by by walls\n");
			}
			else if (w == 0 || w == map->wid - 1)
			{
				if (map->str[h][w] != '1')
					print_error_msg("ERROR\nmap must be closed by by walls\n");
			}
			w++;
		}
		h++;
	}
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
			if (ft_strchr("01PECT", map->str[h][w]) == NULL)
				print_error_msg("ERROR\nmap contain invalid character\n");
			else if (map->str[h][w] == 'P')
				map->p++;
			else if (map->str[h][w] == 'E')
				map->e++;
			else if (map->str[h][w] == 'C')
				map->c++;
			else if (map->str[h][w] == 'T')
				map->t++;
			w++;
		}
		h++;
	}
	check_element_error(map);
}
