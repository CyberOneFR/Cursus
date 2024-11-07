/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:23:06 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/06 14:43:44 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	nmemb *= size;
	ptr = malloc(nmemb);
	if (ptr)
		while (nmemb > 0)
			*((char *)ptr - 1 + nmemb--) = 0;
	else
		return ((void *)0);
	return (ptr);
}
