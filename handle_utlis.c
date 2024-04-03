/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_utlis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:31:03 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/04/03 12:26:11 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	check_char_second(char c)
{
	if (c == '1' || c == 'P' || c == '0'
		|| c == 'E' || c == 'C')
		return (1);
	return (0);
}

void	set_value_ext(t_map *map_pos, int x, int y)
{
	map_pos->ex_y = y;
	map_pos->ex_x = x;
	map_pos->exit++;
}

void	set_value_ply(t_map *map_pos, int x, int y)
{
	map_pos->ply_y = y;
	map_pos->ply_x = x;
	map_pos->ply++;
}
