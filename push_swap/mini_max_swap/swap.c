/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:00:01 by ethebaul          #+#    #+#             */
/*   Updated: 2024/12/18 00:27:06 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack *pile)
{
	int	tmp;

	if (pile->size < 2)
		return (0);
	tmp = pile->stack[0];
	pile->stack[0] = pile->stack[1];
	pile->stack[1] = tmp;
	return (1);
}
