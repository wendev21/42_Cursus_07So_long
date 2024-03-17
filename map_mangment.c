/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_mangment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:38:24 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/03/17 12:02:00 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(char *argv)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd <= 0)
		return (0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		i++;
		line = get_next_line(fd);
	}
	free(line);
	line = NULL;
	close(fd);
	return (i);
}

void	free_map(char **map, t_map *map_pos)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	free(map_pos);
}

char	**create_map(char *argv)
{
	char **map;
	map = malloc(sizeof(char *) * (count_line(argv) + 1));
	if (!map)
		(finish("memory error"), exit(1));
	return (map);
}
t_map	read_map(char *argv)
{
	int		fd;
	int		y;
	t_map	*map_pos;
	char	**map;

	fd = open(argv, O_RDONLY);
	if (fd <= 0)
		(finish("memory error"), exit(1));
	map = create_map(argv);
	if (!map)
		finish("memory problem");
	y = -1;
	while (1)
	{
		map[++y] = get_next_line(fd);
		if (map[y] == NULL)
			break ;
	}
	if (y >= 0 && y < 3)
		finish("empty or not valid map");
	map_pos = malloc(sizeof(t_map));
	init_struct(map_pos);
	(validate_char(map, map_pos), validate_map(map, map_pos));
	(check_value(map, map_pos), check_map(map, map_pos));
	return (close(fd), *map_pos);
}
