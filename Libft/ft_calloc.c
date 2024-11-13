/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:23:06 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/13 09:11:12 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	int		i;

	i = 0;
	ptr = malloc(nmemb * size);
	if (ptr)
	{
		while (i < (int)(nmemb * size))
		{
			((char *)ptr)[i] = 0;
			i++;
		}
	}
	return (ptr);
}
