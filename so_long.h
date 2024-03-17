/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:50:24 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/03/16 16:41:08 by wecorzo-         ###   ########.fr       */
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
# define RESOLUTION_Y 32
# define RESOLUTION_X 32

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

void	exec_prog(char *argv);
void	init_struct(t_map *map);
void	init_struct_cp(t_map *cp_map, t_map *map);
t_map	read_map(char *argv);
void	val_ext(char *str);
void	validate_char(char **map, t_map *map_pos);
void	finish(char *str);
void	validate_map(char **map, t_map *map_pos);
void	check_value(char **map, t_map *map_pos);
void	check_map(char **map, t_map *map_pos);
void	flood_fill(char **map, int y, int x, t_map *pos_orig);
void	free_map(char **map, t_map *map_pos);
#endif
