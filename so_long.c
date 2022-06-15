/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:41:07 by hyko              #+#    #+#             */
/*   Updated: 2022/06/16 02:28:09 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_init(t_map *map, t_img *img)
{
	map->hei = 0;
	map->wid = 0;
	map->p = 0;
	map->c = 0;
	map->e = 0;
	map->error = 0;
	map->x = 0;
	map->y = 0;
	map->cnt = 0;
	map->img = img;
}

void	img_init(t_img *img, void *mlx)
{
	int		img_w;
	int		img_h;

	img_w = 50;
	img_h = 50;
	img->empty = mlx_xpm_file_to_image(mlx, "./images/road.xpm", &img_w, &img_h);
	img->wall = mlx_xpm_file_to_image(mlx, "./images/block.xpm", &img_w, &img_h);
	img->player_R = mlx_xpm_file_to_image(mlx, "./images/rider_R.xpm", &img_w, &img_h);
	img->player_L = mlx_xpm_file_to_image(mlx, "./images/rider_L.xpm", &img_w, &img_h);
	img->exit = mlx_xpm_file_to_image(mlx, "./images/house.xpm", &img_w, &img_h);
	img->collectible = mlx_xpm_file_to_image(mlx, "./images/chicken.xpm", &img_w, &img_h);
	img->direction = 0;
}

void	print_img(t_map *map)
{
	int		h;
	int		w;

	h = 0;
	while (h < map->hei)
	{
		w = 0;
		while (w < map->wid)
		{
			mlx_put_image_to_window(map->mlx, map->win, map->img->empty, w * 50, h * 50);
			if (map->str[h][w] == '1')
				mlx_put_image_to_window(map->mlx, map->win, map->img->wall, w * 50, h * 50);
			else if (map->str[h][w] == 'P' && map->img->direction == 0)
				mlx_put_image_to_window(map->mlx, map->win, map->img->player_R, w * 50, h * 50);
			else if (map->str[h][w] == 'P' && map->img->direction == 1)
				mlx_put_image_to_window(map->mlx, map->win, map->img->player_L, w * 50, h * 50);
			else if (map->str[h][w] == 'E')
				mlx_put_image_to_window(map->mlx, map->win, map->img->exit, w * 50, h * 50);
			else if (map->str[h][w] == 'C')
				mlx_put_image_to_window(map->mlx, map->win, map->img->collectible, w * 50, h * 50);
			w++;
		}
		h++;
	}
}

int	main(int argc, char **argv)
{
	t_img	img;
	t_map	map;

	if (argc != 2)
		return (0);
	map.mlx = mlx_init();
	img_init(&img, map.mlx);
	map_init(&map, &img);
	read_map(argv[1], &map);
	if (map.error == -1)
		return (0);
	map.win = mlx_new_window(map.mlx, (map.wid * 50), (map.hei * 50), "so_long");
	mlx_key_hook(map.win, &key_press, &map);
	//mlx_hook(win, X_EVENT_KEY_PRESS, 0, &key_press, &map);
	print_img(&map);
	mlx_loop(map.mlx);
	return (0);
}
