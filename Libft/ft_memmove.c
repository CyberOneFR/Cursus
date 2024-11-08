/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:28:34 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/07 23:35:44 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	i = n + 1;
	if (dest >= src)
		while (--i > 0 && (dest || src))
			((char *)dest)[i - 1] = ((char *)src)[i - 1];
	else
		while (--i > 0 && (dest || src))
			((char *)dest)[n - i] = ((char *)src)[n - i];
	return (dest);
}
