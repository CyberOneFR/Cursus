/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:56:38 by ethebaul          #+#    #+#             */
/*   Updated: 2024/12/19 16:03:07 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trainer.h"

t_state	*state_generator(void)
{
	unsigned int	i;
	unsigned int	size;
	int				value;
	t_state			*state;

	i = 0;
	if (MAX_SIZE)
		size = MAX_SIZE;
	else
		size = rand() % MAX_RSIZE;
	printf("size = %d\n", size);
	state = malloc(sizeof(t_state));
	state->a = malloc(sizeof(t_stack));
	state->b = malloc(sizeof(t_stack));
	state->a->stack = malloc(sizeof(int) * size);
	state->b->stack = malloc(sizeof(int) * size);
	state->a->capacity = size;
	state->b->capacity = size;
	state->a->size = size;
	state->b->size = 0;
	while (i < size)
	{
		while (!is_unique(state->a->stack, i, value))
		{
			value = rand() % MAX_VALUE;
		}
		state->a->stack[i] = value;
		state->b->stack[i] = 0;
		i++;
	}
	return (state);
}

int	is_unique(int *stack, unsigned int i, int value)
{
	unsigned int	j;

	j = 0;
	while (j < i)
	{
		if (stack[j] == value)
			return (0);
		j++;
	}
	return (1);
}