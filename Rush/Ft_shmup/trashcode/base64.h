/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 00:21:11 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/23 00:53:47 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE64_H
# define BASE64_H

# include <stdlib.h>
# include <string.h>

int	base64_encode(unsigned char *src, int srclen, char *dst);
int	base64_decode(unsigned char *src, int srclen, char *dst);

#endif