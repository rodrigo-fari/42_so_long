/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42poto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:37:31 by rde-fari          #+#    #+#             */
/*   Updated: 2024/07/30 18:02:46 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(char *str)
{
	ft_printf("\n===================================\n");
	ft_putendl_fd(str, 1);
	ft_printf("===================================\n\n");
	exit (1);
}

int	main(int argc, char *argv[])
{
	t_map	*map;

	map = ft_calloc(sizeof(t_map), 1);
	map->full_map = NULL;
	if (argv[1] == NULL)
		print_error("Erro!\nInvalid path.");
	if (argc != 2)
		print_error("Erro!\nInvalid arguments quantity!");
	map_checker(argv[1]);
	map_folder(argv[1]);
	map_extension(argv[1]);
	map_shape(map, argv[1]);
	map_to_struct(map, argv[1]);
	return (0);
}
