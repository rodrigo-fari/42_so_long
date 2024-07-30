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

void	map_shape(t_ms *ms, char *map_path)
{
	int		fd;
	char	*line;
	int		i;
	int		vet_len; 

	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	vet_len = 0;
	ft_printf("\n");
	ms->full_map = ft_calloc(sizeof(char *), 7);
	while (line)
	{
		//A porra do erro esta aqui em baixo comentado !!!!!!!!!!! resolve esta merda animal
		//(motivo: criacao de varios mallocs em um loop :D)
		/* ms->full_map = ft_calloc(sizeof(char), vet_len + 1); */	
		ms->full_map[i] = ft_strdup(line);
		ft_printf("%s", ms->full_map[i]);
		free(line);
		i++;
		vet_len++;
		line = get_next_line(fd);
	}
	ms->full_map[i] = NULL;
	free_tester(ms);
	close (fd);
}

void	free_tester(t_ms *ms)
{
	int i;

	i = 0;
	while(ms->full_map[i])
	{
		free (ms->full_map[i++]);
	}
	free (ms->full_map);
	free (ms);
}
