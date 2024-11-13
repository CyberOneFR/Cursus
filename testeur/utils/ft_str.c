/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 07:26:54 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/13 08:13:36 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exterminalib.h"

char	*ft_str(char *str)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(strlen(str) + 1 * sizeof(char));
	if (!new)
		garbage_collector(ENOMEM);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	return (new);
}
