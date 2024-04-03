/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:10:19 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/03/28 16:27:58 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int y, int x, t_map *pos_orig)
{
	if (y > pos_orig->y || y < 0
		|| x > pos_orig->x || x < 0)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	map[y][x] = 'X';
	flood_fill(map, y - 1, x, pos_orig);
	flood_fill(map, y + 1, x, pos_orig);
	flood_fill(map, y, x - 1, pos_orig);
	flood_fill(map, y, x + 1, pos_orig);
}

int	check_flood_fill(char **cp_map)
{
	int	y;
	int	x;

	y = 0;
	while (cp_map[y])
	{
		x = 0;
		while (cp_map[y][x])
		{
			if (cp_map[y][x] == 'C' || cp_map[y][x] == 'E')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
