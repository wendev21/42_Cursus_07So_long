/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiation_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:07:11 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/03/19 12:07:10 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_map *map)
{
	map->y = 0;
	map->x = 0;
	map->coll = 0;
	map->exit = 0;
	map->ply = 0;
	map->ply_x = 0;
	map->ply_y = 0;
}

void	init_struct_cp(t_map *cp_map, t_map *map)
{
	cp_map->y = map->y;
	cp_map->x = map->x;
	cp_map->coll = map->coll;
	cp_map->exit = map->exit;
	cp_map->ply = map->ply;
	cp_map->ply_x = map->ply_x;
	cp_map->ply_y = map->ply_y;
}

void	init_struct_img(t_img *img)
{
	img->wall = "images/wall.xpm";
	img->bck = "images/bck.xpm";
	img->ply = "images/ply.xpm";
	img->coin = "images/coin.xpm";
	img->exit = "images/exit.xpm";
}
