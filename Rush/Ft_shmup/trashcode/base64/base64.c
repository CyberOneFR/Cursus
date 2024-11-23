/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 00:10:29 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/23 00:38:56 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base64.h"

static const char	base64_table[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int	base64_encode(unsigned char *src, int srclen, char *dst)
{
	unsigned int	ac;
	int				bits;
	int				i;
	char			*cp;

	i = 0;
	ac = 0;
	bits = 0;
	cp = dst;
	while (i < srclen)
	{
		ac = (ac << 8) | src[i];
		bits += 8;
		while (bits >= 6)
		{
			bits -= 6;
			*cp++ = base64_table[(ac >> bits) & 0x3f];
		}
		i++;
	}
	if (bits)
	{
		*cp++ = base64_table[(ac << (6 - bits)) & 0x3f];
		bits -= 6;
	}
	while (bits < 0)
	{
		*cp++ = '=';
		bits += 2;
	}
	return (cp - dst);
}

int	base64_decode(unsigned char *src, int srclen, char *dst)
{
	unsigned int	ac;
	char			*p;
	char			*bp;
	int				bits;
	int				i;

	i = 0;
	ac = 0;
	bits = 0;
	bp = dst;
	while (i < srclen)
	{
		p = strchr(base64_table, src[i]);
		if (src[i] == '=')
		{
			ac = (ac << 6);
			bits += 6;
			if (bits >= 8)
				bits -= 8;
		}
		if (p == NULL || src[i] == 0)
			return (-1);
		ac = (ac << 6) | (p - base64_table);
		bits += 6;
		if (bits >= 8)
		{
			bits -= 8;
			*bp++ = (char)(ac >> bits);
		}
		i++;
	}
	if (ac & ((1 << bits) - 1))
		return (-1);
	return (bp - dst);
}
