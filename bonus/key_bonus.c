/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:27:28 by hyko              #+#    #+#             */
/*   Updated: 2022/06/16 15:36:00 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

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
		map->img->p_direction = 1;
	}
	else if (keycode == KEY_D)
	{
		next.x++;
		map->img->p_direction = 0;
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
	if (map->str[next->y][next->x] != '1' && map->str[next->y][next->x] != 'E')
	{
		if (map->str[next->y][next->x] == 'T')
		{
			ft_putstr("You Lose...\n");
			exit(0);
		}
		if (map->str[next->y][next->x] == 'C')
			map->c--;
		map->str[next->y][next->x] = 'P';
		map->str[map->y][map->x] = '0';
		map->x = next->x;
		map->y = next->y;
		//print_img(map);
		map->cnt++;
		//ft_putstr("move : ");
		//ft_putstr(ft_itoa(map->cnt));
		//write(1, "\n", 1);
		//mlx_string_put(map->mlx, map->win, 15, 25, 100, ft_itoa(map->cnt));
	}
	if (map->str[next->y][next->x] == 'E' && map->c == 0)
	{
		map->cnt++;
		//ft_putstr("move : ");
		//ft_putstr(ft_itoa(map->cnt));
		//ft_putstr("\nYou Win!\n");
		//mlx_string_put(map->mlx, map->win, 15, 25, 100, ft_itoa(map->cnt));
		exit(0);
	}
}

int	click_red_cross(t_map *map)
{
	mlx_destroy_window(map->mlx, map->win);
	exit(0);
	return (0);
}
