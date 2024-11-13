/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_left.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:42:35 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/13 05:27:28 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exterminalib.h"

void	print_left(void *text)
{
	int	i;

	i = 0;
	while (((t_text *)text)->str[i])
	{
		screen_buffer[(((t_text *)text)->p.y * w.ws_row) + i] = ((t_text *)text)->str[i];
		i++;
	}
}
