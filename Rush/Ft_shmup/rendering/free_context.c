/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_context.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 05:56:49 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/23 06:12:33 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"

void	free_context(t_env *env, t_context *new_context)
{
	t_element	*iterator;
	t_element	*deletion;

	iterator = env->context->elements;
	while (iterator)
	{
		deletion = iterator;
		iterator = iterator->next;
		if (deletion->data && deletion->del)
			deletion->del(deletion->data);
		free(deletion);
	}
	free(env->context);
	env->context = new_context;
}
