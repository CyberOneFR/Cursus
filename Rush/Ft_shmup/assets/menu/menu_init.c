/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 05:16:58 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/23 06:40:49 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"

t_context	*menu_init(void)
{
	t_context	*menu;

	menu = malloc(sizeof(t_context));
	if (!menu)
		return (0);
	menu->elements = element_init();
	//last_element(menu->elements)->next = element();
	//add other element to make a menu
	//don't forget to set the selectable elements
	//and the type of the context
	//you can make other asset to simplify the menu creation
	//like a function to create a button or a text or a grid of elements etc
	return (menu);
}
