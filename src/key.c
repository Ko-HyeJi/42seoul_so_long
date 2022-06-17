/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:27:28 by hyko              #+#    #+#             */
/*   Updated: 2022/06/17 14:30:31 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_press(int keycode, t_map *map)
{	
	t_location	next;
	t_location	player;

	find_player(map, &player);
	next = player;
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
		print_error_msg("user terminated the game\n");
	else
		return (0);
	change_map(map, &player, &next);
	return (0);
}

void	find_player(t_map *map, t_location *player)
{
	int		h;
	int		w;

	h = 0;
	while (h < map->hei)
	{
		w = 0;
		while (w < map->wid)
		{
			if (map->str[h][w] == 'P')
			{
				player->x = w;
				player->y = h;
			}
			w++;
		}
		h++;
	}
}

void	change_map(t_map *map, t_location *player, t_location *next)
{
	if (map->str[next->y][next->x] != '1' && map->str[next->y][next->x] != 'E')
	{
		if (map->str[next->y][next->x] == 'C')
			map->c--;
		map->str[next->y][next->x] = 'P';
		map->str[player->y][player->x] = '0';
		print_map(map);
		player->x = next->x;
		player->y = next->y;
		print_step(map);
	}
	if (map->str[next->y][next->x] == 'E' && map->c == 0)
	{
		print_step(map);
		ft_putstr("You Win!\n");
		exit(0);
	}
}

void	print_step(t_map *map)
{
	char	*step;

	map->cnt++;
	step = ft_itoa(map->cnt);
	ft_putstr(step);
	write(1, "\n", 1);
	free(step);
}

int	click_red_cross(t_map *map)
{
	mlx_destroy_window(map->mlx, map->win);
	print_error_msg("user terminated the game\n");
	return (0);
}
