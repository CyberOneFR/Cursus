/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 04:23:26 by ethebaul          #+#    #+#             */
/*   Updated: 2024/12/11 10:45:06 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	strlen_lf(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	if (s[len] == '\n')
		len++;
	return (len);
}

char	*ft_cat(char *buffer1, char *buffer2, int size1, int size2)
{
	char	*buffer;
	int		i;

	i = 0;
	buffer = (char *)malloc((size1 + size2 + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (i < size1)
	{
		buffer[i] = buffer1[i];
		i++;
	}
	while (i < size1 + size2)
	{
		buffer[i] = buffer2[i - size1];
		i++;
	}
	buffer[i] = 0;
	return (buffer);
}

void	ft_move(char *buffer, int size)
{
	size_t	i;

	i = 0;
	while (buffer[i + size])
	{
		buffer[i] = buffer[i + size];
		i++;
	}
	buffer[i] = 0;
}

int	ft_dump(char **line, char *buffer, int size)
{
	char	*new_line;
	int		dump_size;

	dump_size = strlen_lf(buffer);
	new_line = ft_cat(*line, buffer, size, dump_size);
	ft_move(buffer, dump_size);
	free(*line);
	*line = new_line;
	return (dump_size);
}
