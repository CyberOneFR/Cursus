/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:35:59 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/13 05:09:26 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exterminalib.h"

void	free_screen(void)
{
	t_object	*tmp;

	tmp = object_stack;
	while (tmp)
	{
		tmp = tmp->next;
		if (tmp->del)
			tmp->del(tmp->content);
		free(tmp);
	}
	free(screen_buffer);
}
