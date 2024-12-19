/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 04:23:24 by ethebaul          #+#    #+#             */
/*   Updated: 2024/12/11 15:53:43 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			read_size;
	size_t		size;
	char		*line;

	size = 0;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_size = ft_dump(&line, buffer, size);
	while (line && (read_size > 0 || size == 0))
	{
		size += read_size;
		if (line[((size - 1) * (size > 0))] == '\n')
			return (line);
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size < 0)
			return (free(line), NULL);
		buffer[read_size] = 0;
		read_size = ft_dump(&line, buffer, size);
		if (read_size == 0 && size == 0)
			return (free(line), NULL);
	}
	return (line);
}
