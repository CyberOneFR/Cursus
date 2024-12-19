/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 07:14:41 by ethebaul          #+#    #+#             */
/*   Updated: 2024/12/18 12:39:05 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_queue	*queue_new(t_stack *pile_a, t_stack *pile_b, \
	t_inst *inst, float heuristic)
{
	t_queue	*new;

	new = malloc(sizeof(t_queue));
	new->next = NULL;
	new->pile_a = pile_a;
	new->pile_b = pile_b;
	new->inst = inst;
	new->heuristic = heuristic;
	return (new);
}

void	free_queue(t_queue *queue)
{
	free_stack(queue->pile_a);
	free_stack(queue->pile_b);
	free_inst(queue->inst);
	free(queue);
}

t_queue	*dup_queue(t_queue *queue)
{
	t_queue	*new;
	t_stack	*pile_a;
	t_stack	*pile_b;
	t_inst	*inst;

	pile_a = dup_stack(queue->pile_a);
	pile_b = dup_stack(queue->pile_b);
	inst = dup_inst(queue->inst->inst, queue->inst->size);
	new = queue_new(pile_a, pile_b, inst, queue->heuristic);
	return (new);
}

void	add_queue(t_queue **queue, t_queue *new)
{
	t_queue	*tmp;

	if (!*queue)
	{
		*queue = new;
		return ;
	}
	tmp = *queue;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
