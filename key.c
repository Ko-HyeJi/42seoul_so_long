/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:27:28 by hyko              #+#    #+#             */
/*   Updated: 2022/06/14 22:58:52 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_press(int keycode, t_map *map)
{	
    //printf("(x, y): (%d, %d)\n", map->x, map->y);
	t_param	next;
	next.x = map->x;
	next.y = map->y;
	
    if (keycode == KEY_W)
		next.y--;
    else if (keycode == KEY_S)
		next.y++;
    else if (keycode == KEY_A)
		next.x--;
    else if (keycode == KEY_D)
		next.x++;
    else if (keycode == KEY_ESC)
        exit(0);
	if (map->str[next.y][next.x] == 'E' && map->c == 0)
	{
		map->cnt++;
		printf("%d\n", map->cnt);
		exit(0);
	}
	if (map->str[next.y][next.x] != '1' && map->str[next.y][next.x] != 'E')
	{
		map->cnt++;
		printf("%d\n", map->cnt);
		if (map->str[next.y][next.x] == 'C')
			map->c--;
		map->str[next.y][next.x] = 'P';
		map->str[map->y][map->x] = '0';
		map->x = next.x;
		map->y = next.y;
		print_img(map);
	}
    return (0);
}