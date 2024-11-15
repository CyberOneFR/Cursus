/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:58:08 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/15 05:41:06 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			format = ft_option(++format, ap);
		else
			ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(ap);
	return (0);
}

const char	*ft_option(const char *format, va_list ap)
{
	if (*format == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	else if (*format == 's')
		ft_putstr_fd(va_arg(ap, char *), 1);
	else if (*format == 'p')
		ft_putptr_fd(va_arg(ap, void *), 1);
	else if (*format == 'd')
		ft_putnbr_fd(va_arg(ap, int), 1);
	else if (*format == 'i')
		ft_putnbr_fd(va_arg(ap, int), 1);
	else if (*format == 'u')
		ft_putbase_fd(va_arg(ap, unsigned int), "0123456789", 1);
	else if (*format == 'x')
		ft_putbase_fd(va_arg(ap, unsigned int), "0123456789abcdef", 1);
	else if (*format == 'X')
		ft_putbase_fd(va_arg(ap, unsigned int), "0123456789ABCDEF", 1);
	else if (*format == '%')
		ft_putchar_fd('%', 1);
	return (format);
}
