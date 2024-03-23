/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:02:04 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/03/23 17:13:00 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	val_ext(char *str)
{
	int	len;

	len = ft_strlen(str) - 4;
	if (ft_strncmp(str + len, ".ber", 4) != 0)
		finish("Invalid Extension\n");
}

void	validate_char(t_map *map_pos)
{
	size_t	x;
	size_t	y;

	y = 0;
	if (map_pos->map[y] == NULL)
		finish("empty map");
	while (map_pos->map[y])
	{
		if (ft_strlen(map_pos->map[y]) != (size_t)ft_strlen(map_pos->map[0]))
			finish("invalid map");
		x = 0;
		while (map_pos->map[y][x])
		{
			if (map_pos->map[y][x] == '1' || map_pos->map[y][x] == 'P' || map_pos->map[y][x] == '0'
				|| map_pos->map[y][x] == 'E' || map_pos->map[y][x] == 'C' || map_pos->map[y][x] == '\n')
				x++;
			else
				finish("Invalid Map");
		}
		y++;
	}
	if (x == y + 1)
		finish("only  rectangle");
	map_pos->y = y;
	map_pos->x = ft_strlen(map_pos->map[0]);
}

void	validate_map(t_map *map_pos)
{
	size_t	y;
	size_t	x;
	size_t	len;

	y = 0;
	while (map_pos->map[y])
	{
		x = 0;
		len = ft_strlen(map_pos->map[0]);
		while (x <= len)
		{
			if ((x == 0 && map_pos->map[y][x] != '1') ||
				(y == 0 && map_pos->map[y][x] != '1' && x < len - 1))
				finish("Missing Walls");
			if ((x == ft_strlen(map_pos->map[0]) - 1 && map_pos->map[y][len - 2] != '1') ||
				(map_pos->map[y + 1] == NULL && map_pos->map[y][x] != '1' && x < (len - 1)))
				(free_map(map_pos->map, map_pos), finish("Missing Walls"));
			x++;
		}
		y++;
	}
}

void	check_value(t_map *map_pos)
{
	int		x;
	int		y;

	y = 0;
	while (map_pos->map[y])
	{
		x = 0;
		while (map_pos->map[y][x])
		{
			if (map_pos->map[y][x] == 'E')
			{
				map_pos->ex_y = y;
				map_pos->ex_x = x;
				map_pos->exit++;
			}	
			else if (map_pos->map[y][x] == 'C')
				map_pos->coll += 1;
			else if (map_pos->map[y][x] == 'P')
			{
				map_pos->ply++;
				map_pos->ply_y = y;
				map_pos->ply_x = x;
			}
			x++;
		}
		y++;
	}
	if (map_pos->exit != 1 || map_pos->ply != 1 || map_pos->coll < 1)
		(free_map(map_pos->map, map_pos), finish("invalid map (value)"));
}

void	check_map(t_map *map_pos)
{
	char	**cp_map;
	t_map	*cp_pos;
	int		i;

	i = 0;
	cp_pos = malloc(sizeof(t_map));
	cp_map = malloc(sizeof(char *) * (map_pos->y + 1));
	init_struct_cp(cp_pos, map_pos);
	
	return ;
	while (map_pos->map[i] != NULL)
	{
		cp_map[i] = ft_substr(map_pos->map[i], 0, ft_strlen(map_pos->map[i]) - 1);
		i++;
	}
	cp_map[i] = NULL;
	flood_fill(cp_map, cp_pos->ply_y, cp_pos->ply_x, map_pos);
	if (map_pos->coll != 0 || map_pos->exit != 0)
	{
		free_map(map_pos->map, map_pos);
		finish("inaccesible map");
	}
}
