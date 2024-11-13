/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_part.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:32:54 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/13 05:56:52 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exterminalib.h"

void	add_part(t_object *part)
{
	t_object	*tmp;

	if (!part)
		return ;
	if (!object_stack)
	{
		object_stack = part;
		return ;
	}
	tmp = object_stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = part;
}
