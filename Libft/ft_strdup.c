/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:45:29 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/06 15:20:27 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i])
		i++;
	str = malloc(i + 1 * sizeof(char));
	if (!str)
		return ((char *)0);
	str[i + 1] = '\0';
	while (i >= 0)
	{
		str[i] = s[i];
		i--;
	}
	return (str);
}
