/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:25:03 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/07 18:06:10 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	while (i < len && s[start + i])
		i++;
	sub = (char *)malloc(i * sizeof(char));
	if (!sub)
		return ((char *)0);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	return (sub);
}
