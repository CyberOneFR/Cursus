/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 01:17:39 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/14 16:14:21 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		nbr = (nbr * 10) + (*nptr++ - 48);
	return ((int)nbr * sign);
}
