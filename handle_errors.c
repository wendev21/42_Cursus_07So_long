/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:02:04 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/03/28 16:14:51 by wecorzo-         ###   ########.fr       */
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

void	validate_char(t_map *map_p)
{
	size_t	x;
	size_t	y;
	size_t	len;

	len = 0;
	y = 0;
	x = 0;
	if (map_p->map[y] == NULL)
		(free_map(map_p->map, map_p), finish("empty map"));
	while (map_p->map[y])
	{
		len = ft_strlen(map_p->map[y]);
		if (map_p->map[y][len] != '\n' && map_p->map[y][len] != '\0')
			len += 1;
		if (len != ft_strlen(map_p->map[y]))
			(free_map(map_p->map, map_p),finish("not rectangle"));
		x = 0;
		while (map_p->map[y][x] &&  map_p->map[y][x + 1] != '\n')
		{
			if (map_p->map[y][x] == '1' || map_p->map[y][x] == 'P' || map_p->map[y][x] == '0'
				|| map_p->map[y][x] == 'E' || map_p->map[y][x] == 'C')
				x++;
			else
				(free_map(map_p->map, map_p), finish("Invalid Map"));
		}
		y++;
	}
	if (x == y + 1)
		(free_map(map_p->map, map_p), finish("only  rectangle"));
	map_p->y = y;
	map_p->x = ft_strlen(map_p->map[0]);
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
				(free_map(map_pos->map, map_pos), finish("Missing Walls"));
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
		(free_map(map_pos->map, map_pos), finish("invalid map"));
}

void	check_map(t_map *map_pos)
{
	char	**cp_map;
	t_map	*cp_pos;
	int		i;

	i = 0;
	cp_pos = malloc(sizeof(t_map));
	if (!cp_pos)
		(free_map(map_pos->map, map_pos), finish("memory"));
	cp_map = malloc(sizeof(char *) * (map_pos->y + 1));
	if (!cp_map)
		(free_map(map_pos->map, map_pos), finish("memory"));
	init_struct_cp(cp_pos, map_pos);
	while (map_pos->map[i] != NULL)
	{
		cp_map[i] = ft_substr(map_pos->map[i], 0, ft_strlen(map_pos->map[i]) - 1);
		if (!cp_map[i])
			(free_map(map_pos->map, map_pos), finish("memory"));
		i++;
	}
	cp_map[i] = NULL;
	flood_fill(cp_map, cp_pos->ply_y, cp_pos->ply_x, map_pos);
	if (check_flood_fill(cp_map) == 1)
		(free_map(map_pos->map, map_pos), finish("inaccesible map"));
	free_map(cp_map, cp_pos);
}
