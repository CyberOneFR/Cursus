/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:19:19 by ethebaul          #+#    #+#             */
/*   Updated: 2024/12/18 09:25:06 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_load(int size, char **elements)
{
	t_stack	*pile_a;
	int		i;

	pile_a = malloc(sizeof(t_stack));
	pile_a->stack = ft_calloc(size, sizeof(int));
	pile_a->capacity = size;
	pile_a->size = size;
	i = 0;
	while (i < pile_a->size)
	{
		pile_a->stack[i] = ft_atoi(elements[i]);
		i++;
	}
	return (pile_a);
}
