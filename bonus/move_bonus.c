/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:13:52 by hyko              #+#    #+#             */
/*   Updated: 2022/06/17 16:13:50 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	moving_img(t_map *map)
{
	t_location	enemy;

	if (map->time == 10)
	{
		map->time = 0;
		moving_collection(map);
		find_enemy(map, &enemy);
		moving_enemy(map, &enemy);
	}
	map->time++;
	print_map(map);
	print_step_on_game(map);
	return (0);
}

void	moving_collection(t_map *map)
{
	if (map->img->c_direction == 0)
		map->img->c_direction = 1;
	else if (map->img->c_direction == 1)
		map->img->c_direction = 0;
}

void	find_enemy(t_map *map, t_location *enemy)
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
				enemy->x = w;
				enemy->y = h;
			}
			w++;
		}
		h++;
	}
}

void	moving_enemy(t_map *map, t_location *enemy)
{
	if (map->img->e_direction == 0)
	{
		if (map->str[enemy->y + 1][enemy->x] == 'P')
			print_error_msg("You Lose...\n");
		if (map->str[enemy->y + 1][enemy->x] == '0')
		{
			map->str[enemy->y + 1][enemy->x] = 'T';
			map->str[enemy->y][enemy->x] = '0';
		}
		else
			map->img->e_direction = 1;
	}
	else if (map->img->e_direction == 1)
	{
		if (map->str[enemy->y - 1][enemy->x] == 'P')
			print_error_msg("You Lose...\n");
		if (map->str[enemy->y - 1][enemy->x] == '0')
		{
			map->str[enemy->y - 1][enemy->x] = 'T';
			map->str[enemy->y][enemy->x] = '0';
		}
		else
			map->img->e_direction = 0;
	}
}
