/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42poto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:04:30 by rde-fari          #+#    #+#             */
/*   Updated: 2024/08/12 21:30:06 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_checker(t_map *map, char *map_path)
{
	map_folder(map_path, map);
	file_checker(map_path, map);
	map_extension(map_path, map);
	map_shape(map, map_path);
	map_to_struct(map, map_path);
	map_resources(map);
	player_coord(map, map->player);
	exit_coord(map);
	final_map_verification(map);
}

void	map_shape(t_map *map, char *map_path)
{
	int		fd;
	char	*line;
	int		line_size;
	int		read_line;

	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	if (!line || !ft_strcmp("\n", line))
	{
		close(fd);
		free(line);
		print_error("Error!\nInvalid map.", map);
	}
	line_size = ft_strlen(line);
	while (line)
	{
		read_line = ft_strlen(line);
		if (line[ft_strlen(line) - 1] != '\n')
			read_line += 1;
		map->map_lines += 1;
		free(line);
		if (read_line != line_size)
		{
			close(fd);
			print_error("Error!\nMap is not rectangular.", map);
		}
		line = get_next_line(fd);
	}
	free(line);
	close (fd);
}

void	map_to_struct(t_map *map, char *map_path)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	map->map_columns = (ft_strlen(line) - 1);
	map->full_map = ft_calloc(sizeof(char *), map->map_lines + 1);
	map->flooded_map = ft_calloc(sizeof(char *), map->map_lines + 1);
	i = 0;
	while (line)
	{
		map->full_map[i] = ft_strdup(line);
		map->flooded_map[i] = ft_strdup(line);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close (fd);
}
