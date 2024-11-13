/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_part.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:29:48 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/13 05:49:33 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exterminalib.h"

t_object	*new_part(void (*del)(void *), void (*f)(void *), void *content)
{
	t_object	*new;

	new = malloc(sizeof(t_object));
	if (!new)
	{
		free_screen();
		errno = ENOMEM;
		exit(1);
	}
	new->del = del;
	new->f = f;
	new->content = content;
	new->next = 0;
	return (new);
}
