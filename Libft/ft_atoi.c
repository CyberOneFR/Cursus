/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 01:17:39 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/12 22:26:59 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atoi(const char *nptr)
{
	unsigned long long int	nbr;
	int						sign;

	nbr = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if ((*nptr == '+' || *nptr == '-'))
		sign *= 44 - *nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (nbr > 9223372036854775807)
		{
			errno = ERANGE;
			if (sign == 1)
				return (-1);
			return (0);
		}
		nbr = (nbr * 10) + (*nptr++ - 48);
	}
	return ((int)nbr * sign);
}
