/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:27:28 by hyko              #+#    #+#             */
/*   Updated: 2022/06/14 13:47:14 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_press(int keycode, t_map *map) // 어떤 키가 눌렸는지 판단하고,
{                                                // 정의된 행동을 수행하는 함수
    if (keycode == KEY_W)        // W 키를 누르면 param.x값이 1 증가한다.
	    map->x++;
    else if (keycode == KEY_S)   // S 키를 누르면 param.x값이 1 감소한다.
        map->x--;
    else if (keycode == KEY_A)   // A 키를 누르면 param.y값이 1 증가한다.
        map->y++;
    else if (keycode == KEY_D)   // D 키를 누르면 param.y값이 1 감소한다.
        map->y--;
    else if (keycode == KEY_ESC) // ESC 키를 누르면 프로그램 종료
        exit(0);
    printf("(x, y): (%d, %d)\n", map->x, map->y); // param의 값 확인
    return (0);
}
