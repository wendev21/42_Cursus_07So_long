/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:10:19 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/03/16 15:28:55 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(char **map, t_map *map_pos)
{
	char	**cp_map;
	t_map	*cp_pos;
	int		i;

	i = 0;
	cp_pos = malloc(sizeof(t_map));
	cp_map = malloc(sizeof(char *) * (map_pos->y + 1));
	init_struct_cp(cp_pos, map_pos);
	while (map[i] != NULL)
	{
		cp_map[i] = ft_substr(map[i], 0, ft_strlen(map[i]) - 1);
		i++;
	}
	cp_map[i] = NULL;
	flood_fill(cp_map, cp_pos->ply_y, cp_pos->ply_x, map_pos);
	free_map(cp_map, cp_pos, map_pos->y);
	if (map_pos->coll != 0 || map_pos->exit != 0)
	{
		free_map(map, map_pos, map_pos->y + 1);
		finish("inaccesible map");
	}
}

void	flood_fill(char **map, int y, int x, t_map *pos_orig)
{
	if (y > pos_orig->y || y < 0
		|| x > pos_orig->x || x < 0)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	if (map[y][x] == 'C')
		pos_orig->coll--;
	if (map[y][x] == 'E')
		pos_orig->exit--;
	map[y][x] = 'X';
	flood_fill(map, y - 1, x, pos_orig);
	flood_fill(map, y + 1, x, pos_orig);
	flood_fill(map, y, x - 1, pos_orig);
	flood_fill(map, y, x + 1, pos_orig);
}
