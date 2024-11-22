/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 04:23:26 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/20 05:44:11 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		((char *)dest)[i] = ((char *)src)[i];
	i = -1;
	while (++i < n)
		((char *)src)[i] = 0;
}

int	ft_dump(void **line, void *buffer, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size && *(char *)buffer != '\n')
		i++;
	*line = malloc(i + 1);
	if (!*line)
		return (-1);
	ft_memmove(*line, buffer, i);
	((char *)*line)[i] = 0;
	return (i);
}
