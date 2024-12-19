/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:01:09 by ethebaul          #+#    #+#             */
/*   Updated: 2024/12/18 08:12:44 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack *pile)
{
	int	tmp;

	if (pile->size < 2)
		return (1);
	tmp = pile->stack[0];
	pile->stack[0] = pile->stack[1];
	pile->stack[1] = tmp;
	return (0);
}
