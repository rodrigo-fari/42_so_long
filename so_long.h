/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42poto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:41:10 by rde-fari          #+#    #+#             */
/*   Updated: 2024/08/20 21:17:25 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//╔════════════════════════════════════════════════╗
//║                                                ║
//║                 so_long header                 ║
//║                                                ║
//╚════════════════════════════════════════════════╝

#ifndef SO_LONG_H
# define SO_LONG_H

//╔═════════════════════ Library ═══════════════════╗
# include "libft/libft.h"
# include "mlx.h"
# include <stdbool.h>
# include <X11/keysym.h>
# include <X11/Xlib.h>
# include <fcntl.h>
# include <sys/types.h>
//╚═════════════════════════════════════════════════╝
//
//
//
//╔════════════════════ Keycodes ═══════════════════╗
# define ESC 65307
# define W_KEY 119
# define S_KEY 115
# define D_KEY 100
# define A_KEY 97
# define R_ARROW 65363
# define L_ARROW 65361
# define U_ARROW 65362
# define D_ARROW 65364
//╚═════════════════════════════════════════════════╝
//
//
//
//╔═════════════════════ Structs ═══════════════════╗
typedef struct s_player
{
	int				pposx;
	int				pposy;

}		t_player;

typedef struct s_data 
{
	void			*mlx;
	void			*window;
	void			*img[6];
	int				k;
}		t_data;

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
	t_data			*data;
}		t_map;

//╚═════════════════════════════════════════════════╝
//
//
//
//╔══════════════════ flood_fill.c ═════════════════╗
void	exit_coord(t_map *map);
void	map_resources(t_map *map);
void	final_map_verification(t_map *map);
void	flood_fill(char **map, int i, int j, t_map *s_map);
void	player_coord(t_map *map, t_player *play);
//╚═════════════════════════════════════════════════╝
//
//
//
//╔═════════════════ map_checker.c ═════════════════╗
void	map_shape(t_map *map);
void	map_to_struct(t_map *map, char *map_path);
void	map_count_lines(t_map *map, char *map_path);
void	map_checker(t_data *data, t_map *map, char *map_path);
//╚═════════════════════════════════════════════════╝
//
//
//
//╔════════════════ map_validation.c ═══════════════╗
void	map_folder(char *map_path, t_map *map);
void	file_checker(char *map_path, t_map *map);
void	map_extension(char *map_path, t_map *map);
//╚═════════════════════════════════════════════════╝
//
//
//╔══════════════════ mem_clear.c ══════════════════╗
void	mem_clear(t_map *map);
//╚═════════════════════════════════════════════════╝
//
//
//
//╔═══════════════════ so_long.c ═══════════════════╗
void	print_error(char *str, t_map *map);
//╚═════════════════════════════════════════════════╝
//
//
//
//╔═════════════════ mlx_window.c ══════════════════╗
void	load_img(t_data *data);
void	free_handler(t_data *data);
void	mlx_window(t_data *data, t_map *map);
int		key_handler(int keycode, t_data *data);
void	image_to_display(t_data *data, t_map *map);
//╚═════════════════════════════════════════════════╝
//
//
//
//╔════════════════════ End if ═════════════════════╗
#endif
//╚═════════════════════════════════════════════════╝
