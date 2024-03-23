/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mnlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:39:08 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/03/23 17:09:44 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	closed(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}
/*
Up Arrow: 38
Down Arrow: 40
Left Arrow: 37
Right Arrow: 39
*/

void	moves_y(t_map *map_pos, int i)
{
	if (map_pos->map[map_pos->ply_y + i][map_pos->ply_x] == '1')
		return ;
	if (map_pos->map[map_pos->ply_y + i][map_pos->ply_x] == 'C')
		map_pos->coll--;
	if (map_pos->ex_x == map_pos->ply_x
		&& map_pos->ex_y == map_pos->ply_y + i && map_pos->coll == 0)
		(ft_printf("YOU WON!!!"), exit(1));
	map_pos->map[map_pos->ply_y][map_pos->ply_x] = '0';
	map_pos->map[map_pos->ply_y + i][map_pos->ply_x] = 'P';
	map_pos->ply_y += i;
	set_img(map_pos);
}

void	moves_x(t_map *map_pos, int i)
{
	if (map_pos->map[map_pos->ply_y][map_pos->ply_x + i] == '1')
		return ;
	if (map_pos->map[map_pos->ply_y][map_pos->ply_x + i] == 'C')
		map_pos->coll--;
	if (map_pos->ex_x == map_pos->ply_x + i
		&& map_pos->ex_y == map_pos->ply_y && map_pos->coll == 0)
		(ft_printf("YOU WON!!!"), exit(1));
	map_pos->map[map_pos->ply_y][map_pos->ply_x] = '0';
	map_pos->map[map_pos->ply_y][map_pos->ply_x + i] = 'P';
	map_pos->ply_x += i;
	set_img(map_pos);
}

int	key_hook(int keycode, t_map *map_pos)
{
	static int	i;

	if (keycode == 53)
		closed(&map_pos->vars);
	i++;
	if (keycode == 126 || keycode == 13)
		(moves_y(map_pos, -1), ft_printf("%d\n", i));
	else if (keycode == 125 || keycode == 1)
		(moves_y(map_pos, 1), ft_printf("%d\n", i));
	else if (keycode == 124 || keycode == 2)
		(moves_x(map_pos, 1), ft_printf("%d\n", i));
	else if (keycode == 123 || keycode == 0)
		(moves_x(map_pos, -1), ft_printf("%d\n", i));
	return (0);
}
