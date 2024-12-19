/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 07:41:52 by ethebaul          #+#    #+#             */
/*   Updated: 2024/12/18 10:12:55 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_inst(t_inst *inst)
{
	int	i;

	i = 0;
	while (i < inst->size)
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

int	useinst(t_stack *pile_a, t_stack *pile_b, int inst)
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
