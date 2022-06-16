/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:13:52 by hyko              #+#    #+#             */
/*   Updated: 2022/06/16 11:20:33 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	moving_enemy(t_map *map)
{
	int			h;
	int			w;
	static int	sign;

	h = 0;
	while (h < map->hei)
	{
		w = 0;
		while (w < map->wid)
		{
			if (map->str[h][w] == 'T' && sign == 0)
			{
				if (map->str[h + 1][w] == '0')
				{
					map->str[h][w] = '0';
					map->str[h + 1][w] = 'T';
				}
				else
					sign = 1;
			}
			else if (map->str[h][w] == 'T' && sign == 1)
			{
				if (map->str[h - 1][w] == '0')
				{
					map->str[h][w] = '0';
					map->str[h - 1][w] = 'T';
				}
				else
					sign = 0;
			}
			w++;
		}
		h++;
	}
	print_img(map);
	return(0);
}
