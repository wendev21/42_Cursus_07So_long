/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mnlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 12:32:59 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/03/19 15:55:39 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

 void    check_img(char *img_pth, t_vars vars, int y, int x)
{
	int fd;
	int	h;
	int	w;
	char	*img;

	h = 0;
	w = 0;

	fd = open(img_pth, O_RDONLY);
	if (fd <= 0)
		finish("upload img failed");
	img = mlx_xpm_file_to_image(vars.mlx, img_pth, &w, &h);
	mlx_put_image_to_window(vars.mlx, vars.win, img, (y * RESOLUTION), (x * RESOLUTION));

}
/*
void	check_imagen(char **map)
{
	check_img(img->wall);
	check_img(img->bck);
	check_img(img->ply);
	check_img(img->coin);
	check_img(img->exit);
	set_img(img, map);
}*/

void	set_img( char **map, t_vars vars)
{
	int	y;
	int	x;
	t_img	*img_pth;

	img_pth = malloc(sizeof(t_img));
	init_struct_img(img_pth);
	y = 0;
	while(map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				check_img(img_pth->wall, vars, y, x);
			if (map[y][x] == '0' || map[y][x] == 'C' || map[y][x] == 'P')
				check_img(img_pth->bck, vars, y, x);
			if (map[y][x] == 'C')
				check_img(img_pth->coin, vars, y, x);
			if (map[y][x] == 'E')
				check_img(img_pth->exit, vars, y, x);
			if (map[y][x] == 'P')
				check_img(img_pth->ply, vars, y, x);
			x++;
		}
		y++;
	}
}

