/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:56:14 by hyko              #+#    #+#             */
/*   Updated: 2022/06/16 16:59:43 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_error_msg(t_map *map)
{
	if (map->c < 1 || map->p != 1 || map->e != 1)
		map->error = -1;
	if (map->c == 0)
		ft_putstr("ERROR\nneed more collection\n");
	if (map->p == 0)
		ft_putstr("ERROR\nneed a player\n");
	if (map->e == 0)
		ft_putstr("ERROR\nneed an exit\n");
	if (map->p > 1)
		ft_putstr("ERROR\ntoo many players\n");
	if (map->e > 1)
		ft_putstr("ERROR\ntoo many exits\n");
}

void	print_error_msg_2(char *str)
{
	ft_putstr(str);
	exit(0);
}
