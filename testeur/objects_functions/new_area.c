/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_area.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 05:34:03 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/13 05:37:15 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exterminalib.h"

t_area	*new_area(t_point p1, t_point p2, char c)
{
	t_area	*area;

	area = (t_area *) malloc(sizeof(t_area));
	if (!area)
		garbage_collector(ENOMEM);
	area->p1 = p1;
	area->p2 = p2;
	area->c = c;
	return (area);
}
