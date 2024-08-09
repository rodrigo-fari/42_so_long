/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42poto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:04:30 by rde-fari          #+#    #+#             */
/*   Updated: 2024/08/09 20:05:06 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_checker(t_map *map,char *map_path)
{
	map_folder(map_path);
	file_checker(map_path);
	map_extension(map_path);
	map_shape(map, map_path);
	map_to_struct(map, map_path);
	map_resources(map);
	player_gps(map, 'P');
}

void	map_shape(t_map *map, char *map_path)
{
	char	*line;
	int		line_len1;
	int		line_len2;
	int		fd;

	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	line_len1 = (ft_strlen(line) - 1);
	line_len2 = line_len1;
	map->map_lines = 0;
	while (line)
	{
		line_len1 = (ft_strlen(line) - 1);
		if (line_len1 > line_len2)
			print_error("ERRO!\nMap is not retangular.");
		line_len2 = line_len1;
		line = get_next_line(fd);
		map->map_lines += 1;
	}
	if (map->map_lines == (line_len1 + 2))
		print_error("ERRO!\nMap is not retangular.");
	close(fd);
}

void	map_to_struct(t_map *map, char *map_path)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	map->map_columns = (ft_strlen(line) - 1);
	i = 0;
	map->full_map = ft_calloc(sizeof(char *), map->map_lines);
	map->flooded_map = ft_calloc(sizeof(char *), map->map_lines);
	while (line)
	{
		map->full_map[i] = ft_strdup(line);
		map->flooded_map[i] = ft_strdup(line);
		ft_printf("%s", map->full_map[i]);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	map->full_map[i] = NULL;
	close (fd);
}
