/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:03:14 by hyko              #+#    #+#             */
/*   Updated: 2022/06/11 22:33:07 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_copy.h"

t_map	print_error_msg(t_map map)
{
	//if (map.c < 1 || map.p != 1 || map.e != 1)
	//	map.error = -1;
	if (map.error == -1)
		printf("WRONG MAP\n");
	/*if (map.c == 0)
		printf("NEED MORE COLLECTIBLE\n");
	if (map.p == 0)
		printf("NEED A PLAYER\n");
	if (map.e == 0)
		printf("NEED A EXIT\n");
	if (map.p > 1)
		printf("TOO MANY PLAYERS\n");
	if (map.e > 1)
		printf("TOO MANY EXIT\n");*/
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
	//map.str = "";
	map.error = 0;
	return (map);
}

t_map	map_size(t_map map) //가로, 세로, 직사각형인지?
{
	int	i;

	i = 0;
	map.wid = ft_strlen(map.str[0]);
	while (map.str[i] != NULL)
	{
		if (ft_strlen(map.str[i]) != map.wid)
			map.error = -1;
		i++;
	}
	map.hei = i;
	return (map);
}

t_map	map_check(t_map map)
{
	
	return (map);
}

t_map	read_map(char *filename)
{
	int		fd;
	char	*line;
	t_map	map;

	map = map_init();
	fd = open(filename, O_RDONLY);
	map.str = ft_split(filename, '\n');
	map = map_size(map);
	map = print_error_msg(map);
	//map = map_check(map);
	return (map);
}

int main(void)
{
	read_map("11111\n10001\n10001\n11111");
}