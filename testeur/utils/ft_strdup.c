/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:55:06 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/13 05:20:05 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exterminalib.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (0);
	str = malloc(sizeof(char) * (strlen(s) + 1));
	if (!str)
		garbage_collector(ENOMEM);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
