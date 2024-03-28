/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mnlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:39:08 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/03/28 15:45:51 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	closed(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	moves_y(t_map *map_pos, int i)
{
	if (map_pos->map[map_pos->ply_y + i][map_pos->ply_x] == '1')
		return (0);
	if (map_pos->map[map_pos->ply_y + i][map_pos->ply_x] == 'C')
		map_pos->coll--;
	if (map_pos->ex_x == map_pos->ply_x
		&& map_pos->ex_y == map_pos->ply_y + i && map_pos->coll == 0)
		(ft_printf("YOU WON!!!"), exit(1));
	map_pos->map[map_pos->ply_y][map_pos->ply_x] = '0';
	map_pos->map[map_pos->ply_y + i][map_pos->ply_x] = 'P';
	map_pos->ply_y += i;
	set_img(map_pos);
	return (1);
}

int	moves_x(t_map *map_pos, int i)
{
	if (map_pos->map[map_pos->ply_y][map_pos->ply_x + i] == '1')
		return (0);
	if (map_pos->map[map_pos->ply_y][map_pos->ply_x + i] == 'C')
		map_pos->coll--;
	if (map_pos->ex_x == map_pos->ply_x + i
		&& map_pos->ex_y == map_pos->ply_y && map_pos->coll == 0)
		(ft_printf("YOU WON!!!"), exit(1));
	map_pos->map[map_pos->ply_y][map_pos->ply_x] = '0';
	map_pos->map[map_pos->ply_y][map_pos->ply_x + i] = 'P';
	map_pos->ply_x += i;
	set_img(map_pos);
	return (1);
}

int	key_hook(int keycode, t_map *map_pos)
{
	static int	i;
	int			j;

	j = 0;
	if (keycode == 53)
		(free_map(map_pos->map, map_pos), closed(&map_pos->vars));
	if (keycode == 126 || keycode == 13)
		j = moves_y(map_pos, -1);
	else if (keycode == 125 || keycode == 1)
		j = moves_y(map_pos, 1);
	else if (keycode == 124 || keycode == 2)
		j = moves_x(map_pos, 1);
	else if (keycode == 123 || keycode == 0)
		j = moves_x(map_pos, -1);
	if (j == 1)
	{
		i++;
		ft_printf("%d\n", i);
	}
	return (0);
}
