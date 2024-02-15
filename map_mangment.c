/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_mangment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:38:24 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/02/15 16:27:54 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *argv)
{
	int		fd;
	char	**map;
	int		count;
	int		y;

	count = 0;
	fd = open(argv, O_RDONLY);
	y = 0;
	val_ext(argv);
	map = malloc(sizeof(char *));
	while ((map[y] = get_next_line(fd)) != NULL)
		y++;
	validate_char(map);
	valdate_map(map);
	close(fd);
}
