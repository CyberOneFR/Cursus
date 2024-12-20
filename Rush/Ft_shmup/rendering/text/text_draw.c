/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 05:15:02 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/23 06:25:41 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"

void	text_draw(t_element *element)
{
	move(element->p1.y, element->p1.x);
	addstr((char *)element->data);
}
