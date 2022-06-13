/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:41:07 by hyko              #+#    #+#             */
/*   Updated: 2022/06/13 23:00:53 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void param_init(t_param *param) // 구조체 param 초기화 함수
{
    param->x = 0;
    param->y = 0;
}

t_map	map_init(void)
{
	t_map	map;

	map.hei = 0;
	map.wid = 0;
	map.p = 0;
	map.c = 0;
	map.e = 0;
	map.error = 0;
	return (map);
}

t_img	img_init(void *mlx)
{
	t_img	img;
	int		img_w;
	int		img_h;

	img.empty = mlx_xpm_file_to_image(mlx, "./images/road.xpm", &img_w, &img_h);
	img.wall = mlx_xpm_file_to_image(mlx, "./images/tree.xpm", &img_w, &img_h);
	img.player = mlx_xpm_file_to_image(mlx, "./images/rider.xpm", &img_w, &img_h);
	img.exit = mlx_xpm_file_to_image(mlx, "./images/house.xpm", &img_w, &img_h);
	img.collectible = mlx_xpm_file_to_image(mlx, "./images/chicken.xpm", &img_w, &img_h);
	return (img);
}

int main(int argc, char **argv)
{
	t_img	img;
	t_map	map;
	t_param param;
	void	*mlx;
	void	*win;
	int		h;
	int		w;

	map = map_init();
	map = read_map(argv[1], map);
	mlx = mlx_init();
	param_init(&param);
	win = mlx_new_window(mlx, (map.wid * 50), (map.hei * 50), "so_long");
	img = img_init(mlx);

	h = 0;
	while (h < map.hei)
	{
		w = 0;
		while (w < map.wid)
		{
			if (map.str[h][w] == '0')
				mlx_put_image_to_window(mlx, win, img.empty, w * 50, h * 50);
			else if (map.str[h][w] == '1')
				mlx_put_image_to_window(mlx, win, img.wall, w * 50, h * 50);
			else if (map.str[h][w] == 'P')
				mlx_put_image_to_window(mlx, win, img.player, w * 50, h * 50);
			else if (map.str[h][w] == 'E')
				mlx_put_image_to_window(mlx, win, img.exit, w * 50, h * 50);
			else if (map.str[h][w] == 'C')
				mlx_put_image_to_window(mlx, win, img.collectible, w * 50, h * 50);
			w++;
		}
		h++;
	}
	mlx_hook(win, X_EVENT_KEY_PRESS, 0, &key_press, &param); // 키를 잡는 함수
	mlx_loop(mlx);
	return (0);
}
