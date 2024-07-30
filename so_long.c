/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:37:31 by rde-fari          #+#    #+#             */
/*   Updated: 2024/07/30 02:48:33 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(char *str)
{
	ft_putendl_fd(str, 1);
	exit (1);
}

int main (int argc, char *argv[])
{
	if (argc != 2)
		print_error("Erro!\nInvalid arguments quantity!");
	map_checker(argv[1]);
	map_extension(argv[1]);
	map_shape(argv[1]);
	return (0);
}
