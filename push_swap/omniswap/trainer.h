/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trainer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:56:50 by ethebaul          #+#    #+#             */
/*   Updated: 2024/12/19 16:03:22 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRAINER_H
# define TRAINER_H

# define MAX_SIZE 500
# define MAX_RSIZE 500
# define MAX_VALUE 500

# include <stdio.h>
# include <stdlib.h>
# include <time.h>

typedef struct	s_stack
{
	int				*stack;
	unsigned int	capacity;
	unsigned int	size;
}	t_stack;

typedef struct	s_state
{
	t_stack	*a;
	t_stack	*b;
}	t_state;

t_state	*state_generator(void);
void	print_state(t_state *state);
void	quicksort(int *stack, int low, int high);
int		is_unique(int *stack, unsigned int i, int value);

#endif
