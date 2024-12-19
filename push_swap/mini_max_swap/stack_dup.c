/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 04:06:20 by ethebaul          #+#    #+#             */
/*   Updated: 2024/12/18 04:06:40 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_dup(t_stack *pile)
{
	t_stack	*new;
	int		i;

	new = malloc(sizeof(t_stack));
	new->stack = ft_calloc(pile->size, sizeof(int));
	new->size = pile->size;
	i = 0;
	while (i < pile->size)
	{
		new->stack[i] = pile->stack[i];
		i++;
	}
	return (new);
}
