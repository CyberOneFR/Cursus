/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shmup_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 03:42:31 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/23 04:49:51 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"

void	shmup_render(t_env *env)
{
	t_elements	*iterator;

	iterator = env->context->elements;
	while (iterator)
	{
		render_draw(iterator);
		iterator = iterator->next;
	}
}

void	render_draw(t_elements *element)
{
	move(element->p1.x, element->p1.y);
	attron(COLOR_PAIR(element->color));
	attron(element->attr);
	addch(element->c);
	attroff(element->attr);
	attroff(COLOR_PAIR(element->color));
}
