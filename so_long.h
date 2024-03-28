/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:50:24 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/03/28 12:25:58 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdbool.h>
# include <string.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include "Libft/libft.h"

/*----------RESOLUTIONS-------*/
# define RESOLUTION 64

/*-----------STRUCT-----------*/
typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_map
{
	int		y;
	int		x;
	int		coll;
	int		exit;
	int		ex_y;
	int		ex_x;
	int		ply;
	int		ply_x;
	int		ply_y;
	char	**map;
	t_vars	vars;
}	t_map;

typedef struct s_img
{
	char	*wall;
	char	*bck;
	char	*ply;
	char	*coin;
	char	*exit;
}	t_img;

void	exec_prog(t_map *map_pos);
void	parseo(char *argv);
char	**create_map(char *argv);
void	init_struct(t_map *map);
void	init_struct_cp(t_map *cp_map, t_map *map);
void	init_struct_img(t_img *img);
char	**read_map(char *argv, t_map *map_pos);
void	val_ext(char *str);
int		closed(t_vars *vars);
int		key_hook(int keycode, t_map *map_pos);
void	check_img(char *img_pth, t_map *map_pos, int y, int x);
void	validate_char(t_map *map_p);
void	finish(char *str);
void	validate_map(t_map *map_pos);
void	check_value(t_map *map_pos);
void	check_map(t_map *map_pos);
void	flood_fill(char **map, int y, int x, t_map *pos_orig);
int		check_flood_fill(char **cp_map);
void	check_imagen(char	**map);
void	set_img(t_map *map_pos);
void	free_map(char **map, t_map *map_pos);
#endif
