/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:15:44 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/13 05:48:48 by ethebaul         ###   ########.fr       */
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
		add_part(new_part(free_text, print_left, new_text(0, 5, ft_strdup(buffer))));
	}
	else if (read_value == -1)
		garbage_collector(errno);
}
