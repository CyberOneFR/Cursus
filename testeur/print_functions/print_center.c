/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_center.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:20:56 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/13 06:15:47 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exterminalib.h"

void	print_center(void *text)
{
	int				padding;
	int				len;
	int				i;

	i = 0;
	len = printable_len(((t_text *)text)->str);
	padding = (w.ws_col - len) / 2;
	while (((t_text *)text)->str[i])
	{
		screen_buffer[(((t_text *)text)->p.y * w.ws_row) + padding + i] = ((t_text *)text)->str[i];
		i++;
	}
}
