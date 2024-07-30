/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:05:08 by rde-fari          #+#    #+#             */
/*   Updated: 2024/07/30 03:15:11 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *src, char *dest, int param)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		if (param && src[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_char_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_char_strjoin(char *str1, char *str2)
{
	size_t	len;
	char	*ptr;
	int		i;
	int		j;

	len = ft_strlen(str1) + ft_strlen(str2);
	ptr = ft_calloc((len + 1), sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (str1 && str1[i])
	{
		ptr[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2 && str2[j])
		ptr[i++] = str2[j++];
	free(str1);
	return (ptr);
}

int	nline_scan(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
