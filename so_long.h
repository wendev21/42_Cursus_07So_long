/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:50:24 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/03/19 15:33:36 by wecorzo-         ###   ########.fr       */
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
typedef struct s_map
{
	int	y;
	int	x;
	int	coll;
	int	exit;
	int	ply;
	int	ply_x;
	int	ply_y;
}	t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef	struct	s_img
{
	char	*wall;
	char	*bck;
	char	*ply;
	char	*coin;
	char	*exit;
}	t_img;

void	exec_prog(char **map, t_map *map_pos);
void	parseo(char *argv);
char	**create_map(char *argv);
void	init_struct(t_map *map);
void	init_struct_cp(t_map *cp_map, t_map *map);
void	init_struct_img(t_img *img);
t_map	*read_map(char *argv, char **map);
void	val_ext(char *str);
int		closed(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
void	check_img(char *img_pth, t_vars vars, int y, int x);
void	validate_char(char **map, t_map *map_pos);
void	finish(char *str);
void	validate_map(char **map, t_map *map_pos);
void	check_value(char **map, t_map *map_pos);
void	check_map(char **map, t_map *map_pos);
void	flood_fill(char **map, int y, int x, t_map *pos_orig);
void	check_imagen(char	**map);
void	set_img(char **map, t_vars vars);
void	free_map(char **map, t_map *map_pos);
#endif
