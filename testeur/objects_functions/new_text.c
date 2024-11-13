/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 05:04:49 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/13 05:17:31 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exterminalib.h"

t_text	*new_text(int x, int y, char *str)
{
	t_text	*text;

	text = (t_text *) malloc(sizeof(t_text));
	if (!text)
		garbage_collector(ENOMEM);
	text->p.x = x;
	text->p.y = y;
	text->str = ft_strdup(str);
	return (text);
}
