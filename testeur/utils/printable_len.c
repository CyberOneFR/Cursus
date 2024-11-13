/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printable_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 03:13:58 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/13 04:40:46 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exterminalib.h"

int	printable_len(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		if (isprint(*str))
			len++;
		str++;
	}
	return (len);
}
