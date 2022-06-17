/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:56:14 by hyko              #+#    #+#             */
/*   Updated: 2022/06/17 17:10:32 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_element_error(t_map *map)
{
	if (map->c == 0)
		print_error_msg("ERROR\nneed more collection\n");
	if (map->p == 0)
		print_error_msg("ERROR\nneed a player\n");
	if (map->p > 1)
		print_error_msg("ERROR\ntoo many players\n");
	if (map->e == 0)
		print_error_msg("ERROR\nneed an exit\n");
	if (map->e > 1)
		print_error_msg("ERROR\ntoo many exits\n");
}

void	print_error_msg(char *str)
{
	ft_putstr(str);
	exit(0);
}
