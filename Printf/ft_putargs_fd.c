/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putargs_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 04:11:53 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/16 15:05:35 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_printchar_fd(int c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_printstr_fd(char *str, int fd)
{
	int	len;

	len = ft_strlen(str);
	len = write(fd, str, len);
	return (len);
}

int	ft_printptr_fd(void *ptr, int fd)
{
	int	len;

	len = write(fd, "0x", 2);
	len += ft_printbase_fd((unsigned long long)ptr, "0123456789abcdef", fd);
	return (len);
}

int	ft_printbase_fd(unsigned long long n, char *base, int fd)
{
	int	len;

	len = 0;
	if (n >= ft_strlen(base))
	{
		len += ft_printbase_fd(n / ft_strlen(base), base, fd);
		len += ft_printbase_fd(n % ft_strlen(base), base, fd);
	}
	else
		len += ft_printchar_fd(base[n], fd);
	return (len);
}
