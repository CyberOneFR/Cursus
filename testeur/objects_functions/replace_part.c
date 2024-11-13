/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_part.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 07:10:26 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/13 07:14:52 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exterminalib.h"

void	replace_part(t_object *old, t_object *new)
{
	if (!object_stack)
		return ;
	if (old->del)
		old->del(old->content);
	old->content = new->content;
	old->del = new->del;
	old->f = new->f;
	free(new);
}
