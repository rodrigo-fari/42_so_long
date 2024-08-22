/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 23:20:11 by rde-fari          #+#    #+#             */
/*   Updated: 2024/08/20 23:43:55 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

	i = 0;
	while (i <= map->map_lines)
	{
		j = 0;
		while (map->full_map[i][j])
		{
			if (map->full_map[i][j] == '1' && data->img[1])
				mlx_put_image_to_window(data->mlx, data->window, data->img[1], (j * 32), (i * 32));
			if (map->full_map[i][j] == '0' && data->img[0])
				mlx_put_image_to_window(data->mlx, data->window, data->img[0], (j * 32), (i * 32));
			if (map->full_map[i][j] == 'P' && data->img[3])
				mlx_put_image_to_window(data->mlx, data->window, data->img[3], (j * 32), (i * 32));
			if (map->full_map[i][j] == 'E' && data->img[4])
				mlx_put_image_to_window(data->mlx, data->window, data->img[4], (j * 32), (i * 32));
			if (map->full_map[i][j] == 'C' && data->img[2])
				mlx_put_image_to_window(data->mlx, data->window, data->img[2], (j * 32), (i * 32));
			j++;
		}
		i++;
	}
}

void	player_movement(t_map *map, int dx, int dy)
{
	int		new_x;
	int		new_y;

	new_x = map->player->pposx + dx;
	new_y = map->player->pposy + dy;
	if (map->full_map[new_y][new_x] != '1')
		map->full_map[map->player->pposy][map->player->pposx] = '0';
	map->player->pposy = new_y;
	map->player->pposx = new_x;
	map->full_map[new_y][new_x] = 'P';
}