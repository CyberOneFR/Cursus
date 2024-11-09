/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:16:09 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/09 19:55:22 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	nb;
	int	len;
	int	i;

	nb = n;
	len = 0;
	while (nb / 10 != 0)
	{
		nb /= 10;
		len++;
	}
	len++;
	if (n < 0)
		write(fd, "-", 1);
	while (--len >= 0)
	{
		i = 0;
		nb = n;
		while (i++ < len)
			nb /= 10;
		write(fd, &"9876543210123456789"[9 + (nb % 10)], 1);
	}
}
