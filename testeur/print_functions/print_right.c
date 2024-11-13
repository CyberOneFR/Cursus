/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_right.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 04:49:14 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/13 05:26:36 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exterminalib.h"

void	print_right(void *text)
{
	int				padding;
	int				len;
	int				i;

	i = 0;
	len = printable_len(((t_text *)text)->str);
	padding = w.ws_col - len;
	while (((t_text *)text)->str[i])
	{
		screen_buffer[(((t_text *)text)->p.y * w.ws_row) + padding + i] = ((t_text *)text)->str[i];
		i++;
	}
}
