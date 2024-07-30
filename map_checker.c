/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 22:46:06 by rde-fari          #+#    #+#             */
/*   Updated: 2024/07/29 22:46:06 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_checker(char *map_path)
{
	int		fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		print_error("Error!\nUnable to open the file.");
	close (fd);
}

void	map_folder(const char *map_path)
{
	char	*path1;
	char	*path2;
	size_t	map_path_len;

	path1 = "/maps/valid_map/";
	path1 = "/maps/invalid_map/";
	map_path_len = ft_strlen(map_path);
	if (ft_strnstr(map_path, path1, map_path_len) && 
	(ft_strnstr(map_path, path2, map_path_len)) == NULL)
		print_error("ERRO!\nMap is not in the correct folder.");
}

void	map_extension(char *map_path)
{
	char	*extension;

	extension = ft_strrchr(map_path, '.');
	if (ft_strcmp(".ber", extension) != 0)
		print_error("Error!\nInvalid extension.");
}

void	map_shape(t_map *map, char *map_path)
{
	char	*line;
	int		line_len;
	int		fd;

	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	map->map_lines = 0;
	line_len = ft_strlen(line);
	while (line)
	{
		line = get_next_line(fd);
		map->map_lines += 1;
	}
	if (map->map_lines == (line_len - 1))
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
	while (line)
	{
		map->full_map[i] = ft_strdup(line);
		ft_printf("%s", map->full_map[i]);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	map->full_map[i] = NULL;
	printf("\n\n%d\n", map->map_columns);
	close (fd);
}
