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
	mlx_key_hook(data->window, key_handler, data);
	mlx_loop(data->mlx);
}

int		key_handler(int keycode, t_data *data)
{
	if (keycode == ESC)
		free_handler(data);
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

void	load_img(t_data *data)
{
	int		size;

	size = 32;
	data->img[0] = mlx_xpm_file_to_image(data->mlx, "./textures/ground_x32.xpm", &size, &size);
	data->img[1] = mlx_xpm_file_to_image(data->mlx, "./textures/wall_x32.xpm", &size, &size);
	data->img[2] = mlx_xpm_file_to_image(data->mlx, "./textures/collectable_x32.xpm", &size, &size);
	data->img[3] = mlx_xpm_file_to_image(data->mlx, "./textures/player_x32.xpm", &size, &size);
	data->img[4] = mlx_xpm_file_to_image(data->mlx, "./textures/close_chest_x32.xpm", &size, &size);
	data->img[5] = mlx_xpm_file_to_image(data->mlx, "./textures/open_chest_x32.xpm", &size, &size);
}

void image_to_display(t_data *data, t_map *map)
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	y = 0;
	while (i <= map->map_lines)
	{
		j = 0;
		x = 0;
		while (map->full_map[i][j])
		{
			if (map->full_map[i][j] == '1' && data->img[1])
				mlx_put_image_to_window(data->mlx, data->window, data->img[1], (x * 32), (y * 32));
			if (map->full_map[i][j] == '0' && data->img[0])
				mlx_put_image_to_window(data->mlx, data->window, data->img[0], (x * 32), (y * 32));
			if (map->full_map[i][j] == 'P' && data->img[3])
				mlx_put_image_to_window(data->mlx, data->window, data->img[3], (x * 32), (y * 32));
			if (map->full_map[i][j] == 'E' && data->img[4])
				mlx_put_image_to_window(data->mlx, data->window, data->img[4], (x * 32), (y * 32));
			if (map->full_map[i][j] == 'C' && data->img[2])
				mlx_put_image_to_window(data->mlx, data->window, data->img[2], (x * 32), (y * 32));
			j++;
			x++;
		}
		i++;
		y++;
	}
}
