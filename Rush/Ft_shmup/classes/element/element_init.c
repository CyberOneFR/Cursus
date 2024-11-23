/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 05:17:27 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/23 05:38:44 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"

t_element	*element(void)
{
	t_element	*element;

	element = malloc(sizeof(t_element));
	if (!element)
		return (NULL);
	element->p1.x = 0;
	element->p1.y = 0;
	element->p2.x = 0;
	element->p2.y = 0;
	element->c = ' ';
	element->data = 0;
	element->render = 0;
	element->attr = 0;
	element->color = 0;
	element->action = 0;
	element->next = 0;
	return (element);
}
