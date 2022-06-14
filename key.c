/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:27:28 by hyko              #+#    #+#             */
/*   Updated: 2022/06/14 22:34:05 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_press(int keycode, t_map *map)
{	
    printf("(x, y): (%d, %d)\n", map->x, map->y);

    if ((keycode == KEY_W) && map->str[map->y - 1][map->x] != '1')
	{
		map->str[map->y][map->x] = '0';
		map->y--;
	}
    else if (keycode == KEY_S && map->str[map->y + 1][map->x] != '1')
	{
		map->str[map->y][map->x] = '0';
        map->y++;
	}
    else if (keycode == KEY_A && map->str[map->y][map->x - 1] != '1')
    {
		map->str[map->y][map->x] = '0';
        map->x--;
	}
    else if (keycode == KEY_D && map->str[map->y][map->x + 1] != '1' && map->str[map->y][map->x + 1] != 'E')
    {
		map->str[map->y][map->x] = '0';
        map->x++;
	}
    else if (keycode == KEY_ESC)
        exit(0);
	next_step(map);
    return (0);
}

void	next_step(t_map *map)
{
	if (map->str[map->y][map->x] == 'C')
	{
		map->c--;
		printf("%d\n", map->c);
	}
	/*else if (map->str[map->y][map->x] == 'E')
	{
		if (map->c == 0)
		{
			exit(0);
		}
		else
			return ;
	}*/
	map->str[map->y][map->x] = 'P';
	print_img(map);
}
