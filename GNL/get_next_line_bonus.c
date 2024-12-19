/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 04:23:24 by ethebaul          #+#    #+#             */
/*   Updated: 2024/12/11 15:53:45 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[OPEN_MAX][BUFFER_SIZE + 1];
	int			read_size;
	size_t		size;
	char		*line;

	size = 0;
	line = NULL;
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	read_size = ft_dump(&line, buffer[fd], size);
	while (line && (read_size > 0 || size == 0))
	{
		size += read_size;
		if (line[((size - 1) * (size > 0))] == '\n')
			return (line);
		read_size = read(fd, buffer[fd], BUFFER_SIZE);
		if (read_size < 0)
			return (free(line), NULL);
		buffer[fd][read_size] = 0;
		read_size = ft_dump(&line, buffer[fd], size);
		if (read_size == 0 && size == 0)
			return (free(line), NULL);
	}
	return (line);
}
