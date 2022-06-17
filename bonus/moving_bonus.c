/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:13:52 by hyko              #+#    #+#             */
/*   Updated: 2022/06/17 12:23:00 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	find_enemy(t_map *map)
{
	int		h;
	int		w;

	h = 0;
	while (h < map->hei)
	{
		w = 0;
		while (w < map->wid)
		{
			if (map->str[h][w] == 'T')
			{
				map->enemy_x = w;
				map->enemy_y = h;
			}
			w++;
		}
		h++;
	}
}

void	moving_enemy(t_map *map)
{
	int	ex;
	int	ey;

	ex = map->enemy_x;
	ey = map->enemy_y;
	if (map->img->e_direction == 0)
	{
		if (map->str[ey + 1][ex] == 'P')
			exit(0);
		if (map->str[ey + 1][ex] == '0')
		{
			map->str[ey + 1][ex] = 'T';
			map->str[ey][ex] = '0';
			map->enemy_y++;
		}
		else
			map->img->e_direction = 1;
	}
	else if (map->img->e_direction == 1)
	{
		if (map->str[ey - 1][ex] == 'P')
			exit(0);
		if (map->str[ey - 1][ex] == '0')
		{
			map->str[ey - 1][ex] = 'T';
			map->str[ey][ex] = '0';
			map->enemy_y--;
		}
		else
			map->img->e_direction = 0;
	}
}

int	moving_img(t_map *map)
{
	char	*step;

	if ((map->direction_cnt % 10) == 0)
	{
		map->direction_cnt = 0;
		if (map->img->c_direction == 0)
			map->img->c_direction = 1;
		else if (map->img->c_direction == 1)
			map->img->c_direction = 0;
		moving_enemy(map);
	}
	map->direction_cnt++;
	print_img(map);
	step = ft_itoa(map->cnt);
	mlx_string_put(map->mlx, map->win, 15, 25, 1, step);
	free(step);
	return (0);
}
