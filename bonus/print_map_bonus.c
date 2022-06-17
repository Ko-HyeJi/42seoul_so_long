/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:36:02 by hyko              #+#    #+#             */
/*   Updated: 2022/06/17 16:18:15 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	print_map(t_map *map)
{
	int		h;
	int		w;

	h = 0;
	while (h < map->hei)
	{
		w = 0;
		while (w < map->wid)
		{
			print_map_2(map, w, h);
			w++;
		}
		h++;
	}
}

void	print_map_2(t_map *map, int w, int h)
{
	mlx_put_image_to_window(
		map->mlx, map->win, map->img->empty, w * 50, h * 50);
	if (map->str[h][w] == '1')
		mlx_put_image_to_window(
			map->mlx, map->win, map->img->wall, w * 50, h * 50);
	else if (map->str[h][w] == 'P' && map->img->p_direction == 0)
		mlx_put_image_to_window(
			map->mlx, map->win, map->img->player_r, w * 50, h * 50);
	else if (map->str[h][w] == 'P' && map->img->p_direction == 1)
		mlx_put_image_to_window(
			map->mlx, map->win, map->img->player_l, w * 50, h * 50);
	else if (map->str[h][w] == 'E')
		mlx_put_image_to_window(
			map->mlx, map->win, map->img->exit, w * 50, h * 50);
	else if (map->str[h][w] == 'C' && map->img->c_direction == 0)
		mlx_put_image_to_window(
			map->mlx, map->win, map->img->collection_r, w * 50, h * 50);
	else if (map->str[h][w] == 'C' && map->img->c_direction == 1)
		mlx_put_image_to_window(
			map->mlx, map->win, map->img->collection_l, w * 50, h * 50);
	else if (map->str[h][w] == 'T')
		mlx_put_image_to_window(
			map->mlx, map->win, map->img->enemy, w * 50, h * 50);
}

void	print_step(t_map *map)
{
	char	*step;

	ft_putstr("move : ");
	map->cnt++;
	step = ft_itoa(map->cnt);
	ft_putstr(step);
	write(1, "\n", 1);
	free(step);
}

void	print_step_on_game(t_map *map)
{
	char	*step;

	step = ft_itoa(map->cnt);
	mlx_string_put(map->mlx, map->win, 15, 25, 1, step);
	free(step);
}
