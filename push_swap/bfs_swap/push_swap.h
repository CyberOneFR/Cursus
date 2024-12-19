/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:30:31 by ethebaul          #+#    #+#             */
/*   Updated: 2024/12/18 14:39:58 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int	*stack;
	int	capacity;
	int	size;
}	t_stack;

typedef struct s_inst
{
	int	*inst;
	int	size;
}	t_inst;

typedef struct s_queue
{
	struct s_queue	*next;
	t_stack			*pile_a;
	t_stack			*pile_b;
	t_inst			*inst;
	float			heuristic;
}	t_queue;

void	print_stack(t_stack *pile);


void	bfs_sort(t_stack *pile_a, t_stack *pile_b, t_inst *inst);
float	filter_queue(t_queue **queue, int i, float max_heuristic);
float	heuristic(t_queue *queue);
void	bfs_stop(t_queue *queue);

t_queue	*queue_new(t_stack *pile_a, t_stack *pile_b, \
t_inst *inst, float heuristic);
void	add_queue(t_queue **queue, t_queue *new);
t_queue	*dup_queue(t_queue *queue);
void	free_queue(t_queue *queue);

int		is_sorted(t_stack *stack, t_stack *pile_b);
t_stack	*stack_load(int ac, char **av);
t_stack	*dup_stack(t_stack *stack);
void	free_stack(t_stack *stack);

int		useinst(t_stack *pile_a, t_stack *pile_b, int inst);
void	inst_add(t_inst *inst, int value);
int		isulss(t_queue *queue, int action);
int		is_reverse(t_inst *inst, int action);
t_inst	*dup_inst(int *inst, int size);
void	print_inst(t_inst *inst);
void	free_inst(t_inst *inst);

int		push(t_stack *pile_a, t_stack *pile_b);
int		rrotate(t_stack *pile);
int		rotate(t_stack *pile);
int		swap(t_stack *pile);

void	*ft_memove(void *dest, const void *src, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);

#endif