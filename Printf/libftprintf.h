/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 05:14:02 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/15 05:26:48 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

void		ft_putptr_fd(void *ptr, int fd);
void		ft_putbase_fd(unsigned long long n, char *base, int fd);
int			ft_printf(const char *format, ...);
const char	*ft_option(const char *format, va_list ap);

#endif