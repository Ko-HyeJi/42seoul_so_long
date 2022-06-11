/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:41:07 by hyko              #+#    #+#             */
/*   Updated: 2022/06/11 21:56:59 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	void *mlx;
	void *win;
	void *img;
	void *img2;
	void *img3;
	void *img4;
	void *img5;
	int img_width;
	int img_height;
	t_map	map;

	map = read_map(argv[1]);

	mlx = mlx_init();
	win = mlx_new_window(mlx, map.wid * 50, map.hei * 50, "so_long");
	img = mlx_xpm_file_to_image(mlx, "./images/road.xpm", &img_width, &img_height);
	img2 = mlx_xpm_file_to_image(mlx, "./images/tree_1.xpm", &img_width, &img_height);
	img3 = mlx_xpm_file_to_image(mlx, "./images/rider_1.xpm", &img_width, &img_height);
	img4 = mlx_xpm_file_to_image(mlx, "./images/house.xpm", &img_width, &img_height);
	img5 = mlx_xpm_file_to_image(mlx, "./images/chicken.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_put_image_to_window(mlx, win, img2, 50, 0);
	mlx_put_image_to_window(mlx, win, img3, 100, 0);
	mlx_put_image_to_window(mlx, win, img4, 150, 0);
	mlx_put_image_to_window(mlx, win, img5, 200, 0);
	mlx_loop(mlx);
	return (0);
}