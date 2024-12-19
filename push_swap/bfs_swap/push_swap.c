/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 06:58:53 by ethebaul          #+#    #+#             */
/*   Updated: 2024/12/18 09:24:39 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_stack	*pile_a;
	t_stack	*pile_b;
	t_inst	*inst;

	if (ac < 2)
		return (0);
	pile_a = stack_load(ac - 1, av + 1);
	pile_b = malloc(sizeof(t_stack));
	pile_b->stack = ft_calloc(pile_a->size, sizeof(int));
	pile_b->size = 0;
	pile_b->capacity = pile_a->capacity;
	inst = malloc(sizeof(t_inst));
	inst->inst = ft_calloc(1, sizeof(int));
	inst->size = 0;
	bfs_sort(dup_stack(pile_a), dup_stack(pile_b), \
		dup_inst(inst->inst, inst->size));
	free_stack(pile_a);
	free_stack(pile_b);
	free_inst(inst);
	return (0);
}
