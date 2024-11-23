/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 05:48:32 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/23 06:25:33 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"

void	draw_element(t_element *element)
{
	attron(COLOR_PAIR(element->color));
	attron(element->attr);
	if (element->c)
		fill(element->p1, element->p2, element->c);
	if (element->render)
		element->render(element);
	attroff(element->attr);
	attroff(COLOR_PAIR(element->color));
}
