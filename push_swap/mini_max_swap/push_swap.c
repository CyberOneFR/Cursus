/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:30:27 by ethebaul          #+#    #+#             */
/*   Updated: 2024/12/18 07:00:39 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_stack	*pile_a;
	t_stack	*pile_b;

	if (ac < 2)
		return (0);
	pile_a = stack_load(ac - 1, av + 1);
	pile_b = malloc(sizeof(t_stack));
	pile_b->stack = ft_calloc(pile_a->size, sizeof(int));
	pile_b->size = 0;
	sort(pile_a, pile_b);
	free_stack(pile_a);
	free_stack(pile_b);
	return (0);
}
