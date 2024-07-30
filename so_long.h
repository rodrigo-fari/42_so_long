/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:41:10 by rde-fari          #+#    #+#             */
/*   Updated: 2024/07/30 06:15:57 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//=========     Library     =========//
# include "libft/libft.h"
# include "mlx.h"
#include <stdbool.h>
#include <X11/keysym.h>
#include <X11/Xlib.h>
#include <fcntl.h>
#include <sys/types.h>

//=========     Buffer Define     =========//
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

//=========     Functions     =========//
void	print_error(char *str);
void	map_checker(char *map_path);
void	map_extension(char *map_path);

//=========     Struct     =========//
typedef struct	s_mainstruc {
	char			**full_map;
	int				map_lines;
}		t_ms;

//=========     Struct Functions     =========//
void	free_tester(t_ms *ms);
void	map_shape(t_ms *ms, char *map_path);

//=========     EndIf     =========//
#endif