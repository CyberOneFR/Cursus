/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:15:44 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/13 08:07:38 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exterminalib.h"

void	handle_input(void)
{
	char	buffer[1024];
	int		read_value;

	del_part(last_part());
	read_value = read(0, buffer, 1023);
	if (read_value > 0)
	{
		buffer[read_value] = 0;
		resize_screen(0);
		if (!strcmp(buffer, "exit"))
		{
			garbage_collector(0);
			exit(0);
		}
	}
	else if (read_value == -1)
		garbage_collector(errno);
}
