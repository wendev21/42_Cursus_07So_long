/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:38:58 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/03/19 15:46:23 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	leaks(void)
{
	system("leaks -q so_long");
}

void	exec_prog(char **map, t_map *map_pos)
{
	t_vars	vars;
//	char	*img;
	int		h;
	int		w;
//	char	*img_pth;

	h = 0;
	w = 0;
	(void)map_pos;
//	img_pth = "images/bck.xpm";
//	check_imagen(map);
	//updt create map
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, (RESOLUTION * (map_pos->y)), (RESOLUTION * (map_pos->x - 1)), "so_long!");
	set_img(map, vars);
	//img = mlx_xpm_file_to_image(vars.mlx, img_pth, &w, &h);
	//mlx_put_image_to_window(vars.mlx, vars.win, img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}

void	parseo(char *argv)
{
	t_map	*map_pos;
	char	**map;

	val_ext(argv);
	map = create_map(argv);
	map_pos = read_map(argv, map);
	validate_char(map, map_pos);
	validate_map(map, map_pos);
	check_value(map, map_pos);
	check_map(map, map_pos);
	exec_prog(map, map_pos);
}

int	main(int argc, char **argv)
{
	//atexit(leaks);
	if (argc == 2)
		parseo(argv[1]);
	else
		finish("invalid number of paramets\n");
	return (0);
}
