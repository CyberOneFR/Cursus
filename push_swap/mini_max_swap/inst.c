/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 06:02:46 by ethebaul          #+#    #+#             */
/*   Updated: 2024/12/18 07:41:41 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_inst	*new_inst(int size)
{
	t_inst	*new;

	new = malloc(sizeof(t_inst));
	new->inst = ft_calloc(size, sizeof(int));
	new->size = size;
	return (new);
}

int	*dup_inst(int *inst, int size)
{
	int	*new;
	int	i;

	new = ft_calloc(size, sizeof(int));
	i = 0;
	while (i < size)
	{
		new[i] = inst[i];
		i++;
	}
	return (new);
}

int	exinst(t_stack *pile_a, t_stack *pile_b, int inst)
{
	if (inst == 1)
		return (swap(pile_a));
	else if (inst == 2)
		return (swap(pile_b));
	else if (inst == 3)
		return (rotate(pile_a));
	else if (inst == 4)
		return (rrotate(pile_a));
	else if (inst == 5)
		return (rotate(pile_b));
	else if (inst == 6)
		return (rrotate(pile_b));
	else if (inst == 7)
		return (push(pile_a, pile_b));
	else if (inst == 8)
		return (push(pile_b, pile_a));
	return (0);
}

int	not_useless(int action, int last_action)
{
	if (action == 1 && last_action == 1)
		return (0);
	else if (action == 2 && last_action == 2)
		return (0);
	else if (action == 3 && last_action == 4)
		return (0);
	else if (action == 4 && last_action == 3)
		return (0);
	else if (action == 5 && last_action == 6)
		return (0);
	else if (action == 6 && last_action == 5)
		return (0);
	else if (action == 7 && last_action == 8)
		return (0);
	else if (action == 8 && last_action == 7)
		return (0);
	return (1);
}

void	print_inst(t_inst *inst)
{
	int	i;

	i = 0;
	while (inst->inst[i])
	{
		if (inst->inst[i] == 1)
			printf("sa\n");
		else if (inst->inst[i] == 2)
			printf("sb\n");
		else if (inst->inst[i] == 3)
			printf("ra\n");
		else if (inst->inst[i] == 4)
			printf("rra\n");
		else if (inst->inst[i] == 5)
			printf("rb\n");
		else if (inst->inst[i] == 6)
			printf("rrb\n");
		else if (inst->inst[i] == 7)
			printf("pa\n");
		else if (inst->inst[i] == 8)
			printf("pb\n");
		i++;
	}
}
