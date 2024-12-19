/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:59:14 by ethebaul          #+#    #+#             */
/*   Updated: 2024/12/19 16:00:34 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trainer.h"

//basic quicksort implementation

void	quicksort(int *stack, int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	int	tmp;

	if (low < high)
	{
		pivot = low;
		i = low;
		j = high;
		while (i < j)
		{
			while (stack[i] <= stack[pivot] && i <= high)
				i++;
			while (stack[j] > stack[pivot] && j >= low)
				j--;
			if (i < j)
			{
				tmp = stack[i];
				stack[i] = stack[j];
				stack[j] = tmp;
			}
		}
		tmp = stack[j];
		stack[j] = stack[pivot];
		stack[pivot] = tmp;
		quicksort(stack, low, j - 1);
		quicksort(stack, j + 1, high);
	}
}