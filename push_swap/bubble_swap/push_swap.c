/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:30:27 by ethebaul          #+#    #+#             */
/*   Updated: 2024/12/17 23:58:49 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_stack	*pile_a;
	int		i;

	if (ac < 2)
		return (0);
	i = 0;
	pile_a = stack_load(ac - 1, av + 1);
	sort_stack(pile_a);
	return (0);
}

void	sort_stack(t_stack *pile_a)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (i < pile_a->size - 1)
	{
		if (pile_a->stack[0] < pile_a->stack[1])
		{
			ra(pile_a);
			count++;
			i++;
		}
		else
		{
			sa(pile_a);
			count++;
			if (i > 0)
			{
				rra(pile_a);
				count++;
				i--;
			}
		}
	}
	ra(pile_a);
	//print_stack(pile_a);
	//printf("instruction number: %d", count);
}

void	print_stack(t_stack *pile_a)
{
	int	i;

	i = 0;
	printf("stack state--------------------\n");
	while (i < pile_a->size)
	{
		printf("%d\n", pile_a->stack[i]);
		i++;
	}
}

void	sa(t_stack *pile_a)
{
	int	tmp;

	tmp = pile_a->stack[0];
	pile_a->stack[0] = pile_a->stack[1];
	pile_a->stack[1] = tmp;
	printf("sa\n");
}

void	ra(t_stack *pile_a)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = pile_a->stack[0];
	while (i < pile_a->size - 1)
	{
		pile_a->stack[i] = pile_a->stack[i + 1];
		i++;
	}
	pile_a->stack[i] = tmp;
	printf("ra\n");
}

void	rra(t_stack *pile_a)
{
	int	tmp;
	int	i;

	i = pile_a->size - 1;
	tmp = pile_a->stack[i];
	while (i > 0)
	{
		pile_a->stack[i] = pile_a->stack[i - 1];
		i--;
	}
	pile_a->stack[i] = tmp;
	printf("rra\n");
}
