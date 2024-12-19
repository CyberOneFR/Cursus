/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:07:45 by ethebaul          #+#    #+#             */
/*   Updated: 2024/12/18 06:46:03 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *pile_a, t_stack *pile_b)
{
	t_inst	*inst;

	inst = bfs_sort(pile_a, pile_b);
	print_inst(inst);
	free(inst);
}

//0 = start
//1 = sa
//2 = sb
//3 = ra
//4 = rra
//5 = rb
//6 = rrb
//7 = pa
//8 = pb

t_inst	*bfs_sort(t_stack *pile_a, t_stack *pile_b)
{
	t_queue	*queue;
	t_queue	*temp;
	t_inst	*inst;
	int		i;

	inst = NULL;
	queue = new_queue(pile_a, pile_b, NULL);
	while (queue)
	{
		if (is_sorted(queue->pile_a, queue->pile_b))
		{
			inst = queue->inst;
			queue->inst = NULL;
			break ;
		}
		i = 1;
		while (i < 9)
			add_last(&queue, add_branch(queue, i++));
		temp = queue;
		queue = queue->next;
		free_queue(temp);
	}
	clear_queue(queue);
	return (inst);
}

t_queue	*add_branch(t_queue *queue, int newinst)
{
	t_inst	*inst;

	if (queue->inst->inst == NULL \
	|| not_useless(newinst, queue->inst->inst[queue->inst->size - 1]))
	{
		inst = new_inst(queue->inst->size + 1);
		inst->inst = dup_inst(queue->inst->inst, queue->inst->size + 1);
		inst->inst[inst->size - 1] = newinst;
		queue = new_queue(stack_dup(queue->pile_a), \
		stack_dup(queue->pile_b), inst);
		exinst(queue->pile_a, queue->pile_b, newinst);
		return (queue);
	}
	return (NULL);
}

int	is_sorted(t_stack *pile_a, t_stack *pile_b)
{
	int	i;

	i = 0;
	if (pile_b->size)
		return (0);
	while (i < pile_a->size - 1)
	{
		if (pile_a->stack[i] > pile_a->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}
