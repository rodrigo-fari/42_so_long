/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42poto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:02:39 by rde-fari          #+#    #+#             */
/*   Updated: 2024/08/09 12:29:57 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	file_checker(char *map_path)
{
	int		fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		print_error("Error!\nUnable to open the file (Error:fd = -1).");
	close (fd);
}

void	map_folder(char *map_path)
{
	char	*path1;
	size_t	map_path_len;

	path1 = "maps/";
	map_path_len = ft_strlen(map_path);
	if (ft_strnstr(map_path, path1, map_path_len) == NULL)
		print_error("Error!\nMap is not in the correct folder.");
}

void	map_extension(char *map_path)
{
	char	*extension;

	extension = ft_strrchr(map_path, '.');
	if (extension == NULL)
		print_error("Error!\nInvalid extension.");
	if (ft_strcmp(".ber", extension) != 0)
		print_error("Error!\nInvalid extension.");
}
