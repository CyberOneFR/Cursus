/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:35:59 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/13 08:18:34 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exterminalib.h"

void	free_screen(void)
{
	t_object	*tmp;

	while (object_stack)
	{
		if (object_stack->del)
			object_stack->del(object_stack->content);
		tmp = object_stack;
		object_stack = object_stack->next;
		free(tmp);
	}
	if (screen_buffer)
		free(screen_buffer);
}
