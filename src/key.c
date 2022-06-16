/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:27:28 by hyko              #+#    #+#             */
/*   Updated: 2022/06/16 15:53:09 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	else
		return (0);
	change_map(map, &next);
	return (0);
}

void	change_map(t_map *map, t_param *next)
{
	char	*step;

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
		step = ft_itoa(map->cnt);
		ft_putstr("move : ");
		ft_putstr(step);
		write(1, "\n", 1);
		free(step);
	}
	if (map->str[next->y][next->x] == 'E' && map->c == 0)
	{
		map->cnt++;
		step = ft_itoa(map->cnt);
		ft_putstr("move : ");
		ft_putstr(step);
		ft_putstr("\nYou Win!\n");
		free(step);
		exit(0);
	}
}

int	click_red_cross(t_map *map)
{
	mlx_destroy_window(map->mlx, map->win);
	exit(0);
	return (0);
}
