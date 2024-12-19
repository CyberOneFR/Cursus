/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 07:11:29 by ethebaul          #+#    #+#             */
/*   Updated: 2024/12/18 09:44:13 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*dup_stack(t_stack *stack)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	new->size = stack->size;
	new->capacity = stack->capacity;
	new->stack = ft_calloc(stack->capacity, sizeof(int));
	new->stack = ft_memove(new->stack, stack->stack, stack->size * sizeof(int));
	return (new);
}

void	free_stack(t_stack *stack)
{
	free(stack->stack);
	free(stack);
}

int	is_sorted(t_stack *stack, t_stack *pile_b)
{
	int	i;

	if (pile_b->size)
		return (0);
	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->stack[i] > stack->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	print_stack(t_stack *pile)
{
	int	i;

	i = 0;
	while (i < pile->size)
	{
		printf("%d\n", pile->stack[i]);
		i++;
	}
}
