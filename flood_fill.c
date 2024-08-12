/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42poto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:48:17 by rde-fari          #+#    #+#             */
/*   Updated: 2024/08/12 18:18:01 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_resources(t_map *map)
{
	int		i;

	i = 0;
	while (map->full_map[i])
	{
		map->collectables += ft_str_chr_count(map->full_map[i], 'C');
		map->player_number += ft_str_chr_count(map->full_map[i], 'P');
		map->exit_number += ft_str_chr_count(map->full_map[i], 'E');
		i++;
	}
	if (map->collectables <= 0)
		print_error("Error!\nInvalid number of collectables.");
	if (map->player_number != 1)
		print_error("Error!\nInvalid number of players.");
	if (map->exit_number != 1)
		print_error("Error!\nInvalid number of exit points.");
}
void	player_coord(t_map *map, t_player *play)
{
	int		i;
	int		search_p;

	i = 0;
	while(map->full_map[i])
	{
		search_p = ft_matrix_finder(map->full_map[i], 'P');
		if (search_p != 0)
		{
			play->pposx = search_p;
			play->pposy = i;
		}
		i++;
	}
}
void	exit_coord(t_map *map)
{
	int		i;
	int		search_e;

	i = 0;
	while (map->full_map[i])
	{
		search_e = ft_matrix_finder(map->full_map[i], 'E');
		if (search_e != 0)
		{
			map->exit_x = search_e ;
			map->exit_y = i;
		}
		i++;
	}
}

void	flood_fill(char **map, int i, int j)
{
	if (map[i][j] == '1' || map[i][j] == 'G')
		return ;
	map[i][j] = 'G';
	flood_fill(map, i + 1, j);
	flood_fill(map, i - 1, j);
	flood_fill(map, i, j + 1);
	flood_fill(map, i, j - 1);
}

void	final_map_verification(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	flood_fill(map->flooded_map, map->player->pposy, map->player->pposx);
	while (map->flooded_map[i])
	{
		j = 0;
		while (map->flooded_map[i][j] && map->flooded_map[i][j] != '\n')
		{
			if (map->flooded_map[i][j] != 'G' && map->flooded_map[i][j] != '1')
				print_error("Error!\nMap is no enclosed by walls.");
			j++;
		}
		i++;
	}
}
