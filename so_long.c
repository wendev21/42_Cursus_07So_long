/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:38:58 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/03/17 11:50:15 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	leaks(void)
{
	system("leaks -q so_long");
}

int	closed( t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		closed(vars);
	return (0);
}

void	check_img(char *img, t_map *map)
{
	int fd;

	fd = open(img, O_RDONLY);
	if (fd <= 0)
		(free_map(map), finish("upload img failed"));
}

void	exec_prog(char *argv)
{
	t_map	map_pos;
	t_vars	vars;
	void	*img;
	int		h;
	int		w;
	char	*img_pth;
	char	**map;

	img_pth = "images/backgrund.xpm";

	check_img(img_pth, &map_pos, create_map(argv));
	val_ext(argv);
	map = create_map(argv);
	//updt create map
	map_pos = read_map(argv, map);
	h = (map_pos.y * RESOLUTION_Y);
	w = (map_pos.x * RESOLUTION_X);
	vars.mlx = mlx_init();
	//return ;
	vars.win = mlx_new_window(vars.mlx, 500, 500, "so_long!");
	img = mlx_xpm_file_to_image(vars.mlx, img_pth, &w, &h);
	mlx_put_image_to_window(vars.mlx, vars.win, img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}

int	main(int argc, char **argv)
{
	//atexit(leaks);
	if (argc == 2)
		exec_prog(argv[1]);
	else
		finish("invalid number of paramets\n");
	return (0);
}
