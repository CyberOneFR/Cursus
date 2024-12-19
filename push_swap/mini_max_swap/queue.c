/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 05:15:16 by ethebaul          #+#    #+#             */
/*   Updated: 2024/12/18 06:31:36 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_queue	*new_queue(t_stack *pile_a, t_stack *pile_b, t_inst *inst)
{
	t_queue	*new;

	new = ft_calloc(1, sizeof(t_queue));
	new->pile_a = pile_a;
	new->pile_b = pile_b;
	new->inst = inst;
	return (new);
}

void	free_queue(t_queue *queue)
{
	free(queue->pile_a->stack);
	free(queue->pile_a);
	free(queue->pile_b->stack);
	free(queue->pile_b);
	free(queue->inst->inst);
	free(queue->inst);
	free(queue);
}

void	add_last(t_queue **queue, t_queue *new)
{
	t_queue	*last;

	if (*queue == NULL)
		*queue = new;
	else
	{
		last = *queue;
		while (last->next)
			last = last->next;
		last->next = new;
	}
}

void	clear_queue(t_queue *queue)
{
	t_queue	*temp;

	while (queue)
	{
		temp = queue;
		queue = queue->next;
		free_queue(temp);
	}
}
