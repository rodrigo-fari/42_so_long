/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42poto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:29:52 by rde-fari          #+#    #+#             */
/*   Updated: 2024/08/20 18:37:56 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mem_clear(t_map *map)
{
	int		i;

	i = 0;
	if(map->full_map)
	{
		while (i <= map->map_lines)
		{
			free(map->full_map[i]);
			free(map->flooded_map[i]);
			i++;
		}
	free(map->full_map);
	free(map->flooded_map);
	}
	free(map->player);
	free(map);
}
