/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 05:37:37 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/23 06:14:50 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"

t_element	*last_element(t_element *element)
{
	if (!element)
		return (0);
	while (element->next)
		element = element->next;
	return (element);
}
