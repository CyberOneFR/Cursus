/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 23:59:57 by ethebaul          #+#    #+#             */
/*   Updated: 2024/12/18 08:10:46 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack *pile_a, t_stack *pile_b)
{
	int	i;

	if (pile_b->size < 1)
		return (0);
	i = pile_a->size;
	while (i > 0)
	{
		pile_a->stack[i] = pile_a->stack[i - 1];
		i--;
	}
	pile_a->stack[0] = pile_b->stack[0];
	while (i < pile_b->size - 1)
	{
		pile_b->stack[i] = pile_b->stack[i + 1];
		i++;
	}
	pile_a->size++;
	pile_b->size--;
	return (1);
}
