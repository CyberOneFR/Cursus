/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:00:05 by ethebaul          #+#    #+#             */
/*   Updated: 2024/12/18 01:38:20 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_stack *pile)
{
	int	tmp;
	int	i;

	if (pile->size < 2)
		return (0);
	i = 0;
	tmp = pile->stack[0];
	while (i < pile->size - 1)
	{
		pile->stack[i] = pile->stack[i + 1];
		i++;
	}
	pile->stack[i] = tmp;
	return (1);
}

int	rrotate(t_stack *pile)
{
	int	tmp;
	int	i;

	if (pile->size < 2)
		return (0);
	i = pile->size - 1;
	tmp = pile->stack[i];
	while (i > 0)
	{
		pile->stack[i] = pile->stack[i - 1];
		i--;
	}
	pile->stack[i] = tmp;
	return (1);
}
