/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 07:02:06 by ethebaul          #+#    #+#             */
/*   Updated: 2024/12/18 14:49:51 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bfs_sort(t_stack *pile_a, t_stack *pile_b, t_inst *inst)
{
	float	max_heuristic;
	t_queue	*queue;
	t_queue	*new;
	int		i;

	queue = queue_new(pile_a, pile_b, inst, 0.0);
	while (queue)
	{
		max_heuristic = queue->heuristic;
		if (is_sorted(queue->pile_a, queue->pile_b) && !queue->pile_b->size)
			return (bfs_stop(queue));
		i = 0;
		while (++i < 9)
			max_heuristic = filter_queue(&queue, i, max_heuristic);
		new = queue;
		queue = queue->next;
		free_queue(new);
	}
}

void	bfs_stop(t_queue *queue)
{
	t_queue	*tmp;

	print_inst(queue->inst);
	while (queue)
	{
		tmp = queue;
		queue = queue->next;
		free_queue(tmp);
	}
}

float	filter_queue(t_queue **queue, int i, float max_heuristic)
{
	t_queue	*new;

	if (isulss(*queue, i))
		return (max_heuristic);
	new = dup_queue(*queue);
	inst_add(new->inst, i);
	if (useinst(new->pile_a, new->pile_b, i))
		free_queue(new);
	else
	{
		new->heuristic = heuristic(new);
		//if (new->heuristic > (*queue)->heuristic)
		//{
			add_queue(queue, new);
			max_heuristic = new->heuristic;
		//}
		//else
			//free_queue(new);
	}
	return (max_heuristic);
}
