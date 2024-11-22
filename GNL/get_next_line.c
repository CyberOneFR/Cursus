/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 04:23:24 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/22 18:03:01 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			size;
	char		*line;

	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	size = 0;
	while (size)
	{
		size += read(fd, buffer, BUFFER_SIZE);
		if (size <= 0)
			return (NULL);
		if (ft_dump(&line, buffer, size) != -1)
			return (ft_stop(line));
		ft_memmove(buffer, buffer + size, BUFFER_SIZE - size);
	}
	return (line);
}
