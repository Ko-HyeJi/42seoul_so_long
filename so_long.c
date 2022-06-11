/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:41:07 by hyko              #+#    #+#             */
/*   Updated: 2022/06/10 15:52:13 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main()
{
	void *mlx;
	void *win;
	void *img;
	void *img2;
	void *img3;
	void *img4;
	void *img5;
	//void *img6;
	//void *img7;
	int img_width;
	int img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "my_mlx");
	img = mlx_xpm_file_to_image(mlx, "./images/road.xpm", &img_width, &img_height);
	img2 = mlx_xpm_file_to_image(mlx, "./images/tree_1.xpm", &img_width, &img_height);
	img3 = mlx_xpm_file_to_image(mlx, "./images/rider_1.xpm", &img_width, &img_height);
	img4 = mlx_xpm_file_to_image(mlx, "./images/house.xpm", &img_width, &img_height);
	img5 = mlx_xpm_file_to_image(mlx, "./images/chicken.xpm", &img_width, &img_height);
	//img6 = mlx_xpm_file_to_image(mlx, "./images/rune.xpm", &img_width, &img_height);
	//img7 = mlx_xpm_file_to_image(mlx, "./images/rune_light.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_put_image_to_window(mlx, win, img2, 50, 0);
	mlx_put_image_to_window(mlx, win, img3, 100, 0);
	mlx_put_image_to_window(mlx, win, img4, 150, 0);
	mlx_put_image_to_window(mlx, win, img5, 200, 0);
	//mlx_put_image_to_window(mlx, win, img6, 64, 64);
	//mlx_put_image_to_window(mlx, win, img7, 128, 64);
	mlx_loop(mlx);
	return (0);
}