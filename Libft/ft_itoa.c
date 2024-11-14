/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:33:32 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/14 16:24:06 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		temp;
	int		len;

	len = 0;
	temp = n;
	while (temp / 10 != 0)
	{
		temp /= 10;
		len++;
	}
	len++;
	str = (char *)malloc((len + 1 + (n < 0)) * sizeof(char));
	if (!str)
		return ((char *)0);
	if (n < 0)
		str[0] = '-';
	str[len + (n < 0)] = '\0';
	while (--len >= 0)
	{
		str[len + (n < 0)] = "9876543210123456789"[(n % 10) + 9];
		n /= 10;
	}
	return (str);
}
