/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 07:18:20 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/13 08:19:36 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exterminalib.h"

char	*ft_strcat(char *str1, char *str2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str1 || !str2)
		return (0);
	new = malloc(strlen(str1) + strlen(str2) + 1);
	if (!new)
		garbage_collector(ENOMEM);
	while (str1[j])
		new[i++] = str1[j++];
	j = 0;
	while (str2[j])
		new[i++] = str2[j++];
	new[i] = 0;
	free(str1);
	free(str2);
	return (new);
}
