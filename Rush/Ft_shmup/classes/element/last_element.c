/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 05:37:37 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/23 05:38:21 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"

t_element	*last_element(t_element *element)
{
	while (element->next)
		element = element->next;
	return (element);
}
