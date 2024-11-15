/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putargs_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 04:11:53 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/15 05:43:00 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putptr_fd(void *ptr, int fd)
{
	ft_putstr_fd("0x", fd);
	ft_putbase_fd((unsigned long long)ptr, "0123456789abcdef", fd);
}

void	ft_putbase_fd(unsigned long long n, char *base, int fd)
{
	if (n >= ft_strlen(base))
	{
		ft_putbase_fd(n / ft_strlen(base), base, fd);
		ft_putbase_fd(n % ft_strlen(base), base, fd);
	}
	else
		ft_putchar_fd(base[n], fd);
}
