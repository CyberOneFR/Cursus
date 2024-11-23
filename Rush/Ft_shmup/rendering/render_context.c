/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_context.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 05:50:19 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/23 06:09:47 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"

void	render_context(t_env *env)
{
	t_element	*iterator;

	iterator = env->context->elements;
	while (iterator)
	{
		render_draw(iterator);
		if (iterator->render)
			iterator->render(iterator);
		iterator = iterator->next;
	}
}
