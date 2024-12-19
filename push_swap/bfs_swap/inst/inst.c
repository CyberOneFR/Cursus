/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 06:54:23 by ethebaul          #+#    #+#             */
/*   Updated: 2024/12/18 09:03:46 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_inst	*dup_inst(int *inst, int size)
{
	t_inst	*new;

	new = malloc(sizeof(t_inst));
	new->size = size;
	new->inst = ft_calloc(new->size, sizeof(int));
	new->inst = ft_memove(new->inst, inst, size * sizeof(int));
	return (new);
}

void	inst_add(t_inst *inst, int value)
{
	int	*new;
	int	i;

	new = ft_calloc(inst->size + 1, sizeof(int));
	i = 0;
	while (i < inst->size)
	{
		new[i] = inst->inst[i];
		i++;
	}
	new[i] = value;
	free(inst->inst);
	inst->inst = new;
	inst->size++;
}

void	free_inst(t_inst *inst)
{
	free(inst->inst);
	free(inst);
}
