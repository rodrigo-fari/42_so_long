/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */	
/*   By: rde-fari <rde-fari@student.42poto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:38:16 by rde-fari          #+#    #+#             */
/*   Updated: 2024/08/20 17:25:09 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_window(t_data *data, t_map *map)
{
	int		x;
	int		y;

	x = (map->map_columns + 1);
	y = (map->map_lines + 1);
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, (x * 32), (y * 32), "so_long");
	load_img(data);
	image_to_display(data, map);
	mlx_key_hook(data->window, key_handler, map);
	mlx_loop(data->mlx);
}

int		key_handler(int keycode, t_map *map)
{
	if (keycode == ESC)
		free_handler(map->data);
	if (keycode == U_ARROW || keycode == W_KEY)
		player_movement(map, 0, -1);
	if (keycode == D_ARROW || keycode == S_KEY)
		player_movement(map, 0, 1);
	if (keycode == R_ARROW || keycode == D_KEY)
		player_movement(map, -1, 0);
	if (keycode == L_ARROW || keycode == A_KEY)
		player_movement(map, 1, 0);
	image_to_display(map->data, map);
	return (0);
}
//Problema do ft_calloc na main (1 error from 1 context).
void	free_handler(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
	exit(0);
}
