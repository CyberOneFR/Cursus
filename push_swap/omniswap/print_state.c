/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:31:46 by ethebaul          #+#    #+#             */
/*   Updated: 2024/12/19 15:51:28 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trainer.h"

void	print_state(t_state *state)
{
	unsigned int	i;

	i = 0;
	printf("| A\n");
	while (i < state->a->capacity)
	{
		printf("|%*d|%*d|\n", 6, state->a->stack[i], 6, state->b->stack[i]);
		i++;
	}
}