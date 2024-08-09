/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42poto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:48:17 by rde-fari          #+#    #+#             */
/*   Updated: 2024/08/09 20:09:20 by rde-fari         ###   ########.fr       */
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
void	player_gps(t_map *map, int c)
{
	int		j;
	int		i;

	i = 0;
	while (map->full_map[i])
	{
		j = ft_strnlen(map->full_map[i], c);
		i++;
	}
	map->player->pposx = j;
	map->player->pposy = i;
	ft_printf("\nx:%d\n", j);
	ft_printf("\ny:%d\n", i);
}
