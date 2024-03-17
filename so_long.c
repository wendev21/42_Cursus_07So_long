/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:38:58 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/03/17 12:04:53 by wecorzo-         ###   ########.fr       */
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

void	check_img(char *img)
{
	int fd;

	fd = open(img, O_RDONLY);
	if (fd <= 0)
		finish("upload img failed");
}


void	exec_prog(char *argv)
{
	t_map	map_pos;
	t_vars	vars;
	void	*img;
	int		h;
	int		w;
	char	*img_pth;

	img_pth = "images/background.xpm";
	val_ext(argv);
	check_img(img_pth);	
	//updt create map
	map_pos = read_map(argv);
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
