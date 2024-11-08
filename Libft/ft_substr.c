/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:25:03 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/07 21:39:36 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	i = 0;
	while (s[i])
		i++;
	if (start > (unsigned int)i)
		start = i;
	if (len > (i - start))
		len = i - start;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return ((char *)0);
	i = -1;
	while (++i < (int)len && s[start + i])
		sub[i] = s[start + i];
	sub[i] = '\0';
	return (sub);
}
