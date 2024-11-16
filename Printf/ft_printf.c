/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:58:08 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/16 15:06:50 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			len += ft_option(++format, ap);
		else
			len += ft_printchar_fd(*format, 1);
		format++;
	}
	va_end(ap);
	return (len);
}

int	ft_option(const char *format, va_list ap)
{
	if (*format == 'c')
		return (ft_printchar_fd(va_arg(ap, int), 1));
	else if (*format == 's')
		return (ft_printstr_fd(va_arg(ap, char *), 1));
	else if (*format == 'p')
		return (ft_printptr_fd(va_arg(ap, void *), 1));
	else if (*format == 'd')
		return (ft_printbase_fd(va_arg(ap, int), "0123456789", 1));
	else if (*format == 'i')
		return (ft_printbase_fd(va_arg(ap, int), "0123456789", 1));
	else if (*format == 'u')
		return (ft_printbase_fd(va_arg(ap, unsigned int), "0123456789", 1));
	else if (*format == 'x')
		return (ft_printbase_fd(va_arg(ap, unsigned int), "0123456789abcdef", 1));
	else if (*format == 'X')
		return (ft_printbase_fd(va_arg(ap, unsigned int), "0123456789ABCDEF", 1));
	else if (*format == '%')
		return (ft_printchar_fd('%', 1));
	return (0);
}
