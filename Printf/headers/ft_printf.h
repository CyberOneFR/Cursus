/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 05:14:02 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/20 02:09:56 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_option(const char *format, va_list ap);
int	ft_putchar(int c, int fd);
int	ft_putstr(char *str, int fd);
int	ft_putptr(void *ptr, int fd);
int	ft_putbase(__int64_t n, char *base, int fd);

#endif