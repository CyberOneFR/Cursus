/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state2vec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:05:43 by ethebaul          #+#    #+#             */
/*   Updated: 2024/12/19 16:08:27 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trainer.h"

int	*state2vec(t_state *state)
{
	int	vec[7];

	vec[0] = state->a->capacity;
	vec[1] = state->a->size;
	vec[2] = state->b->size;
	vec[3] = entropy(state->a->stack, state->a->size);
	return (vec);
}