/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mnlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 12:32:59 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/03/28 15:43:37 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_img(char *img_pth, t_map *map_pos, int y, int x)
{
	int		fd;
	int		h;
	int		w;
	char	*img;

	h = 0;
	w = 0;
	y = y * RESOLUTION;
	x = x * RESOLUTION;
	fd = open(img_pth, O_RDONLY);
	if (fd <= 0)
		finish("upload img failed");
	img = mlx_xpm_file_to_image(map_pos->vars.mlx, img_pth, &w, &h);
	if (!img)
		finish("mlx xpm");
	mlx_put_image_to_window(map_pos->vars.mlx, map_pos->vars.win, img, x, y);
	close(fd);
}

void	set_img( t_map *map_pos)
{
	int		y;
	int		x;
	t_img	*img_pth;

	img_pth = malloc(sizeof(t_img));
	init_struct_img(img_pth);
	y = -1;
	while (map_pos->map[++y])
	{
		x = -1;
		while (map_pos->map[y][++x])
		{
			if (map_pos->coll == 0)
				check_img(img_pth->exit, map_pos, map_pos->ex_y, map_pos->ex_x);
			if (map_pos->map[y][x] == '1')
				check_img(img_pth->wall, map_pos, y, x);
			else if (map_pos->map[y][x] == '0' || map_pos->map[y][x] == 'E')
				check_img(img_pth->bck, map_pos, y, x);
			else if (map_pos->map[y][x] == 'C')
				check_img(img_pth->coin, map_pos, y, x);
			else if (map_pos->map[y][x] == 'P')
				check_img(img_pth->ply, map_pos, y, x);
		}
	}
	free(img_pth);
}
