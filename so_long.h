/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42poto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:41:10 by rde-fari          #+#    #+#             */
/*   Updated: 2024/07/30 17:42:54 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//=========     Buffer Define     =========//
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

//=========     Library     =========//
# include "libft/libft.h"
# include "mlx.h"
# include <stdbool.h>
# include <X11/keysym.h>
# include <X11/Xlib.h>
# include <fcntl.h>
# include <sys/types.h>

//=========     Struct     =========//
typedef struct s_map
{
	char			**full_map;
	int				map_lines;
	int				map_columns;
}		t_map;

//=========     Functions     =========//
void	print_error(char *str);
void	map_checker(char *map_path);
void	map_extension(char *map_path);
void	map_folder(const char *map_path);
void	map_shape(t_map *map, char *map_path);
void	map_to_struct(t_map *map, char *map_path);

//=========     EndIf     =========//
#endif