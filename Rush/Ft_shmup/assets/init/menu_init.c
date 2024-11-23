/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 05:16:58 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/23 05:17:10 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"

t_context	*menu_init(void)
{
	t_context	*menu;

	menu = malloc(sizeof(t_context));
	if (!menu)
		return (0);
	menu->elements = menu_elements();
}
