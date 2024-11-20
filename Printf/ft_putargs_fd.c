/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putargs_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 04:11:53 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/20 03:48:23 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putstr(char *str, int fd)
{
	size_t	len;

	if (!str)
		str = "(null)";
	len = 0;
	while (str[len])
		len++;
	return (write(fd, str, len));
}

int	ft_putptr(void *ptr, int fd)
{
	size_t	len;

	len = 0;
	if (!ptr)
		return (ft_putstr("(nil)", fd));
	if ((__uint64_t)ptr > 15)
		len += ft_putptr((void *)((__uint64_t)ptr >> 4), fd);
	else
		len += ft_putstr("0x", fd);
	len += ft_putchar("0123456789abcdef"[(__uint64_t)ptr & 0xf], fd);
	return (len);
}

int	ft_putbase(__int64_t n, char *base, int fd)
{
	__int64_t	len;
	int			mod;
	__int64_t	base_len;

	len = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (n > base_len - 1 || n < -base_len + 1)
		len += ft_putbase(n / base_len, base, fd);
	else if (n < 0)
		len += ft_putchar('-', fd);
	mod = n % base_len;
	if (mod < 0)
		mod *= -1;
	len += ft_putchar(base[mod], fd);
	return (len);
}
