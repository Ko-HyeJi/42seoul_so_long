/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:03:14 by hyko              #+#    #+#             */
/*   Updated: 2022/06/11 16:05:05 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	struct_init(void)
{
	t_map	map;
	map.hei = 0;
	map.wid = 0;
	map.p = 0;
	map.c = 0;
	map.e = 0;
	return (map);
}

t_map	read_map(char *filename)
{
	int		fd;
	char	*line;
	t_map	map;
	int		count;

	map = struct_init();
	fd = open(filename, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			map.hei += 1;
			if (map.hei == 1)
			{
				while (line[map.wid] != '\n')
					map.wid++;
			}
			else
			{
				count = 0;
				while (line[count] != '\n')
					count++;
				if (count != map.wid)
					map.wid = -1;
			}
		}
		else
			break ;
	}
	return (map);
}

int	main(void)
{
	t_map	map;

	map = read_map("map.ber");
	if (map.wid == -1)
		printf("WRONG MAP\n");
	else
		printf("%d * %d\n", map.hei, map.wid);
	return (0);
}
