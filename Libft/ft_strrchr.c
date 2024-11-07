/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 22:51:29 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/05 23:12:00 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*si;
	int		i;

	i = 0;
	si = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			si = (char *)s + i;
		i++;
	}
	if (s[i] == (char) c)
		si = (char *)s + i;
	return (si);
}
