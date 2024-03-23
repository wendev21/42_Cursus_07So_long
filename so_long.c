/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:38:58 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/03/23 17:03:19 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	leaks(void)
{
	system("leaks -q so_long");
	atexit(leaks);
}

void	exec_prog(t_map *map_pos)
{
	int	h;
	int	w;
	int	y;
	int	x;

	h = 0;
	w = 0;
	y = RESOLUTION * map_pos->y;
	x = (RESOLUTION * (map_pos->x - 1));
	map_pos->vars.mlx = mlx_init();
	map_pos->vars.win = mlx_new_window(map_pos->vars.mlx, x, y, "so_long!");
	set_img(map_pos);
	mlx_hook(map_pos->vars.win, 2, 1L << 0, key_hook, map_pos);
	mlx_loop(map_pos->vars.mlx);
}

void	parseo(char *argv)
{
	t_map	*map_pos;

	val_ext(argv);
	map_pos = malloc(sizeof(t_map));
	if (!map_pos)
		finish("memory problem");
	init_struct(map_pos);
	map_pos->map = create_map(argv);
	map_pos->map = read_map(argv, map_pos);
	validate_char(map_pos);
	validate_map(map_pos);
	check_value(map_pos);
	check_map(map_pos);
	exec_prog(map_pos);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		parseo(argv[1]);
	else
		finish("invalid number of paramets\n");
	return (0);
}
