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

void	map_extension(char *map_path)
{
	char	*extension;

	extension = ft_strrchr(map_path, '.');
	if (ft_strcmp(".ber", extension) != 0)
		print_error("Error!\nInvalid extension.");
}

// Resolver problema do get next line
//(testar o do quisk para verificar se o erro nao e la)
void	map_shape(char *map_path)
{
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	
	close (fd);
}
