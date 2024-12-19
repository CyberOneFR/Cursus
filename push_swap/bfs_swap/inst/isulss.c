/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isulss.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:12:48 by ethebaul          #+#    #+#             */
/*   Updated: 2024/12/18 14:38:15 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isulss(t_queue *queue, int action)
{
	if (is_reverse(queue->inst, action))
		return (1);
	return (0);
}

int	is_reverse(t_inst *inst, int action)
{
	if (inst->size == 0)
		return (0);
	else if (action == 1 && inst->inst[inst->size - 1] == 1)
		return (1);
	else if (action == 2 && inst->inst[inst->size - 1] == 2)
		return (1);
	else if (action == 3 && inst->inst[inst->size - 1] == 4)
		return (1);
	else if (action == 4 && inst->inst[inst->size - 1] == 3)
		return (1);
	else if (action == 5 && inst->inst[inst->size - 1] == 6)
		return (1);
	else if (action == 6 && inst->inst[inst->size - 1] == 5)
		return (1);
	else if (action == 7 && inst->inst[inst->size - 1] == 8)
		return (1);
	else if (action == 8 && inst->inst[inst->size - 1] == 7)
		return (1);
	return (0);
}

float	heuristic(t_queue *queue)
{
	float	heuristic;
	int		i;

	i = -1;
	heuristic = 0.0;
	while (++i < queue->pile_a->size - 1)
		if (queue->pile_a->stack[i] < queue->pile_a->stack[i + 1])
			heuristic++;
	i = -1;
	while (++i < queue->pile_b->size - 1)
		if (queue->pile_b->stack[i] > queue->pile_b->stack[i + 1])
			heuristic++;
	return (heuristic);
}
