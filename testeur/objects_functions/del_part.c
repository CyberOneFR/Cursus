/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_part.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 03:45:08 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/13 04:14:28 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exterminalib.h"

void	del_part(t_object *part)
{
	t_object	*tmp;

	if (!part || !object_stack)
		return ;
	tmp = object_stack;
	if (tmp == part)
	{
		object_stack = tmp->next;
		if (tmp->del)
			tmp->del(tmp->content);
		free(tmp);
	}
	else
	{
		while (tmp->next != part)
			tmp = tmp->next;
		tmp->next = part->next;
		if (part->del)
			part->del(part->content);
		free(part);
	}
}
