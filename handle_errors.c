/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:02:04 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/03/17 12:03:17 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	finish(char	*str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	write(2, "\n", 2);
	exit(0);
}

void	val_ext(char *str)
{
	int	len;

	len = ft_strlen(str) - 4;
	if (ft_strncmp(str + len, ".ber", 4) != 0)
		finish("Invalid Extension\n");
}

void	validate_char(char **map, t_map *map_pos)
{
	size_t	x;
	size_t	y;

	y = 0;
	if (map[y] == NULL)
		(free_map(map, map_pos), finish("empty map"));
	while (map[y])
	{
		if (ft_strlen(map[y]) != (size_t)ft_strlen(map[0]))
			finish("invalid map");
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1' || map[y][x] == 'P' || map[y][x] == '0'
				|| map[y][x] == 'E' || map[y][x] == 'C' || map[y][x] == '\n')
				x++;
			else
				finish("Invalid Map");
		}
		y++;
	}
	if (x == y + 1)
		finish("only  rectangle");
	map_pos->y = y;
	map_pos->x = ft_strlen(map[0]);
}

void	validate_map(char **map, t_map *map_pos)
{
	size_t	y;
	size_t	x;
	size_t	len;

	y = 0;
	while (map[y])
	{
		x = 0;
		len = ft_strlen(map[0]);
		while (x <= len)
		{
			if ((x == 0 && map[y][x] != '1') ||
				(y == 0 && map[y][x] != '1' && x < len - 1))
				(free_map(map, map_pos), finish("Missing Walls"));
			if ((x == ft_strlen(map[0]) - 1 && map[y][len - 2] != '1') ||
				(map[y + 1] == NULL && map[y][x] != '1' && x < (len - 1)))
				(free_map(map, map_pos), finish("Missing Walls"));
			x++;
		}
		y++;
	}
}

void	check_value(char **map, t_map *map_pos)
{
	int		x;
	int		y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
				map_pos->exit++;
			else if (map[y][x] == 'C')
				map_pos->coll += 1;
			else if (map[y][x] == 'P')
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
		(free_map(map, map_pos), finish("invalid map (value)"));
}
