/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42poto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:41:10 by rde-fari          #+#    #+#             */
/*   Updated: 2024/08/09 20:03:52 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//=========     Library     =========//
# include "libft/libft.h"
# include "mlx.h"
# include <stdbool.h>
# include <X11/keysym.h>
# include <X11/Xlib.h>
# include <fcntl.h>
# include <sys/types.h>

//=========     Struct     =========//
typedef struct s_player
{
	int				pposx;
	int				pposy;

}		t_player;

typedef struct s_map
{
	char			**full_map;
	char			**flooded_map;
	int				map_lines;
	int				map_columns;
	int				collectables;
	int				player_number;
	int				exit_number;
	int				exit_x;
	int				exit_y;
	t_player		*player;
}		t_map;

//=========     Functions by files     =========//
void	print_error(char *str);
void	map_resources(t_map *map);
void	map_folder(char *map_path);
void	file_checker(char *map_path);
void	player_gps(t_map *map, int c);
void	map_extension(char *map_path);
void	map_shape(t_map *map, char *map_path);
void	map_checker(t_map *map,char *map_path);
void	map_to_struct(t_map *map, char *map_path);

//=========     EndIf     =========//
#endif