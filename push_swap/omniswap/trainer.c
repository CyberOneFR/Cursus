/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trainer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:56:36 by ethebaul          #+#    #+#             */
/*   Updated: 2024/12/19 16:00:50 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trainer.h"

int	main(void)
{
	t_state	*state;

	srand(time(NULL));
	state = state_generator();
	quicksort(state->a->stack, 0, state->a->capacity - 1);
	print_state(state);
	return (0);
}