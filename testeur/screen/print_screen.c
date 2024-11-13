/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 00:58:21 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/13 08:09:14 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exterminalib.h"

struct winsize	w;
char		*screen_buffer;
t_object	*object_stack;

void	print_screen(void)
{
	t_object	*tmp;

	if (!object_stack)
		return ;
	tmp = object_stack;
	while (tmp)
	{
		(tmp->f)(tmp->content);
		tmp = tmp->next;
	}
	system("clear");
	write(1, screen_buffer, w.ws_col * w.ws_row);
}
