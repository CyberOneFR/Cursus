/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:19:19 by ethebaul          #+#    #+#             */
/*   Updated: 2024/12/17 22:19:23 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_load(int size, char **elements)
{
	t_stack	*pile_a;
	int		i;

	pile_a = malloc(sizeof(t_stack));
	pile_a->size = size;
	pile_a->stack = ft_calloc(pile_a->size, sizeof(int));
	i = 0;
	while (i < pile_a->size)
	{
		pile_a->stack[i] = ft_atoi(elements[i]);
		i++;
	}
	return (pile_a);
}
