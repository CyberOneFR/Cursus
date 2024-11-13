/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:44:08 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/13 03:19:39 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exterminalib.h"

int	dict_search(char **dictionary, char *str)
{
	int	i;

	i = 0;
	if (!dictionary || !str)
		return (0);
	while (dictionary[i])
	{
		if (strcmp(dictionary[i], str) == 0)
			return (1);
		i++;
	}
	return (i);
}
