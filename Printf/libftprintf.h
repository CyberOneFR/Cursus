/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 05:14:02 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/16 15:05:45 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_option(const char *format, va_list ap);
int ft_printchar_fd(int c, int fd);
int	ft_printstr_fd(char *str, int fd);
int	ft_printptr_fd(void *ptr, int fd);
int	ft_printbase_fd(unsigned long long n, char *base, int fd);

#endif