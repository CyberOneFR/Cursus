/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 04:02:02 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/13 06:14:36 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exterminalib.h"

void	fill(void *area)
{
	int	x;
	int	y;

	y = ((t_area *)area)->p1.y;
	while (y < ((t_area *)area)->p2.y && y < w.ws_row)
	{
		x = ((t_area *)area)->p1.x;
		while (x < ((t_area *)area)->p2.x && x < w.ws_col)
		{
			screen_buffer[(y * w.ws_row) + x] = ((t_area *)area)->c;
			x++;
		}
		y++;
	}
}
