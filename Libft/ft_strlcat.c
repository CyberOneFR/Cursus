/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 22:02:31 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/05 22:43:53 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	c;

	c = 0;
	while (c < size && dst[c])
		c++;
	i = c;
	while (i + 1 < size && src[i - c])
	{
		dst[i] = src[i - c];
		i++;
	}
	if (size > 0 && c != i)
		dst[i] = '\0';
	while (src[i - c])
		i++;
	return (i);
}
