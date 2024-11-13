/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_part.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 05:39:59 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/13 05:54:15 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exterminalib.h"

t_object	*last_part(void)
{
	t_object	*tmp;

	if (!object_stack)
		return (0);
	tmp = object_stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
