/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:08:49 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/02/15 16:29:54 by wecorzo-         ###   ########.fr       */
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
# include "Libft/libft.h"
# include <mlx.h>

void	exec_prog(char *argv);
void	read_map(char *argv);
void	finish(char *str);
void	validate_char(char **map);
void	val_ext(char *str);
void	validate_map(char **map);
#endif
