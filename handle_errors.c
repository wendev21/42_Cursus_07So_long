/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:02:04 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/04/03 12:29:00 by wecorzo-         ###   ########.fr       */
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

	y = -1;
	while (map_p->map[++y])
	{
		len = ft_strlen(map_p->map[y]);
		if (map_p->map[y][len] != '\n' && map_p->map[y][len] != '\0')
			len += 1;
		if (len != ft_strlen(map_p->map[y]))
			(free_map(map_p->map, map_p), finish("not rectangle"));
		x = 0;
		while (map_p->map[y][x] && map_p->map[y][x + 1] != '\n')
		{
			if (check_char_second(map_p->map[y][x]) == 1)
				x++;
			else
				(free_map(map_p->map, map_p), finish("Invalid Map"));
		}
	}
	if (x == y + 1)
		(free_map(map_p->map, map_p), finish("only  rectangle"));
	map_p->y = y;
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
		map_pos->x = len;
		while (x <= len)
		{
			if ((x == 0 && map_pos->map[y][x] != '1') ||
				(y == 0 && map_pos->map[y][x] != '1' && x < len - 1))
				(free_map(map_pos->map, map_pos), finish("Missing Walls"));
			if ((x == ft_strlen(map_pos->map[0]) - 1
					&& map_pos->map[y][len - 2] != '1')
				|| (map_pos->map[y + 1] == NULL
				&& map_pos->map[y][x] != '1' && x < (len - 1)))
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

	y = -1;
	while (map_pos->map[++y])
	{
		x = -1;
		while (map_pos->map[y][++x])
		{
			if (map_pos->map[y][x] == 'E')
				set_value_ext(map_pos, x, y);
			else if (map_pos->map[y][x] == 'C')
				map_pos->coll += 1;
			else if (map_pos->map[y][x] == 'P')
				set_value_ply(map_pos, x, y);
		}
	}
	if (map_pos->exit != 1 || map_pos->ply != 1 || map_pos->coll < 1)
		(free_map(map_pos->map, map_pos), finish("invalid map"));
}

void	check_map(t_map *map_pos)
{
	char	**cp_m;
	t_map	*cp_pos;
	int		i;

	i = 0;
	cp_pos = malloc(sizeof(t_map));
	if (!cp_pos)
		(free_map(map_pos->map, map_pos), finish("memory"));
	cp_m = malloc(sizeof(char *) * (map_pos->y + 1));
	if (!cp_m)
		(free_map(map_pos->map, map_pos), finish("memory"));
	init_struct_cp(cp_pos, map_pos);
	while (map_pos->map[i] != NULL)
	{
		cp_m[i] = ft_substr(map_pos->map[i], 0, ft_strlen(map_pos->map[i]) - 1);
		if (!cp_m[i])
			(free_map(map_pos->map, map_pos), finish("memory"));
		i++;
	}
	cp_m[i] = NULL;
	flood_fill(cp_m, cp_pos->ply_y, cp_pos->ply_x, map_pos);
	if (check_flood_fill(cp_m) == 1)
		(free_map(map_pos->map, map_pos), finish("inaccesible map"));
	free_map(cp_m, cp_pos);
}
