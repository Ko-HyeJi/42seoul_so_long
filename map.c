/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:03:14 by hyko              #+#    #+#             */
/*   Updated: 2022/06/11 21:37:28 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	print_error_msg(t_map map)
{
	if (map.c < 1 || map.p != 1 || map.e != 1)
		map.error = -1;
	if (map.error == -1)
		printf("WRONG MAP\n");
	if (map.c == 0)
		printf("NEED MORE COLLECTIBLE\n");
	if (map.p == 0)
		printf("NEED A PLAYER\n");
	if (map.e == 0)
		printf("NEED A EXIT\n");
	if (map.p > 1)
		printf("TOO MANY PLAYERS\n");
	if (map.e > 1)
		printf("TOO MANY EXIT\n");
	return (map);
}

t_map	map_init(void)
{
	t_map	map;

	map.hei = 0;
	map.wid = 0;
	map.p = 0;
	map.c = 0;
	map.e = 0;
	map.str = "";
	map.error = 0;
	return (map);
}

t_map	map_size(t_map map, char *line)
{
	int	cnt;

	map.hei += 1;
	if (map.hei == 1)
	{
		while (line[map.wid] != '\n')
			map.wid++;
	}
	else
	{
		cnt = 0;
		while (line[cnt] != '\n' && line[cnt] != '\0')
			cnt++;
		if (cnt != map.wid)
			map.error = -1;
	}
	return (map);
}

t_map	map_check(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.hei)
	{
		j = 0;
		while (j < map.wid + 1)
		{
			if (i == 0 || i == map.hei - 1)
			{	
				if (j < map.wid && map.str[(map.wid * i) + i + j] != '1')
					map.error = -1;
			}
			else
			{
				if ((j == 0 || j == map.wid - 1)
					&& (map.str[(map.wid * i) + i + j] != '1'))
					map.error = -1;
				else if (map.str[(map.wid * i) + i + j] == 'C')
					map.c++;
				else if (map.str[(map.wid * i) + i + j] == 'P')
					map.p++;
				else if (map.str[(map.wid * i) + i + j] == 'E')
					map.e++;
				else if (ft_strchr("10CPE\n\0", map.str[(map.wid * i) + i + j]) == NULL)
					map.error = -1;
			}
			j++;
		}
		i++;
	}
	map = print_error_msg(map);
	return (map);
}

t_map	read_map(char *filename)
{
	int		fd;
	char	*line;
	t_map	map;

	map = map_init();
	fd = open(filename, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			map = map_size(map, line);
			map.str = ft_strjoin(map.str, line);
		}
		else if (line == NULL || map.wid == -1)
			break ;
	}
	map = map_check(map);
	return (map);
}
