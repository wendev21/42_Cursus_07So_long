/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:02:04 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/02/15 16:30:19 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	finish(char	*str)
{
	ft_putstr_fd("Error ", 2);
	ft_putstr_fd(str, 2);
	exit(0);
}

void	val_ext(char *str)
{
	int	len;

	len = ft_strlen(str) - 4;
	if (ft_strncmp(str + len, ".ber", 4) != 0)
		finish("Invalid Extension\n");
}

void	validate_char(char **map)
{
	int		x;
	int		y;
	char	c;

	x = 0;
	y = 0;
	if (map[y] == NULL)
		finish("empty map");
	while (map[y])
	{
		while (map[y][x])
		{
			c = map[y][x];
			if (c == '1' || c == 'P' || c == '0' || c == 'E' || c == 'C')
				x++;
			else
				finish("map invalid\n");
		}
		y++;
	}
}

void	validate_map(char **map)
{

}
