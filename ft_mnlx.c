/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mnlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:39:08 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/03/19 17:03:17 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	closed(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}
/*
Up Arrow: 38
Down Arrow: 40
Left Arrow: 37
Right Arrow: 39
*/
int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		closed(vars);
	if (keycode == 126 || keycode == 34)
		printf("UP");;
	if (keycode == 125 || keycode == 37)
		printf("DOWN");
	if (keycode == 124 || keycode == 40)
		printf("right");
	if (keycode == 123 || keycode == 38)
		printf("left");
	/*else
		printf("key code\n%d", keycode);
		*/
	return (0);
}
