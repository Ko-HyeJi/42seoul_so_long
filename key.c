/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:27:28 by hyko              #+#    #+#             */
/*   Updated: 2022/06/15 23:21:04 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_map *map)
{	
	t_param	next;

	next.x = map->x;
	next.y = map->y;
	if (keycode == KEY_W)
		next.y--;
	else if (keycode == KEY_S)
		next.y++;
	else if (keycode == KEY_A)
	{
		next.x--;
		map->img->direction = 1;
	}
	else if (keycode == KEY_D)
	{
		next.x++;
		map->img->direction = 0;
	}
	else if (keycode == KEY_ESC)
		exit(0);
	change_img(map, &next);
	return (0);
}

void	change_img(t_map *map, t_param *next)
{
	if (map->str[next->y][next->x] != '1' && map->str[next->y][next->x] != 'E')
	{
		if (map->str[next->y][next->x] == 'C')
			map->c--;
		map->str[next->y][next->x] = 'P';
		map->str[map->y][map->x] = '0';
		map->x = next->x;
		map->y = next->y;
		print_img(map);
		map->cnt++;
		ft_putnbr(map->cnt);
		write(1, "\n", 1);
	}
	if (map->str[next->y][next->x] == 'E' && map->c == 0)
	{
		map->cnt++;
		ft_putnbr(map->cnt);
		write(1, "\n", 1);
		exit(0);
	}
}
