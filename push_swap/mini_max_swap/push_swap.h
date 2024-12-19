/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:30:31 by ethebaul          #+#    #+#             */
/*   Updated: 2024/12/18 06:46:31 by ethebaul         ###   ########.fr       */
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
}	t_queue;

t_inst	*bfs_sort(t_stack *pile_a, t_stack *pile_b);

t_stack	*stack_dup(t_stack *pile);
void	free_stack(t_stack *pile);
int		is_sorted(t_stack *pile_a, t_stack *pile_b);
t_stack	*stack_load(int size, char **elements);
void	sort(t_stack *pile_a, t_stack *pile_b);

void	print_inst(t_inst *inst);
t_inst	*new_inst(int size);
void	add_last(t_queue **queue, t_queue *new);
t_queue	*add_branch(t_queue *queue, int newinst);
int		*dup_inst(int *inst, int size);
int		exinst(t_stack *pile_a, t_stack *pile_b, int inst);
int		not_useless(int action, int last_action);

t_queue	*new_queue(t_stack *pile_a, t_stack *pile_b, t_inst *inst);
void	free_queue(t_queue *queue);
void	add_last(t_queue **queue, t_queue *new);
void	clear_queue(t_queue *queue);

void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);

int		swap(t_stack *pile);
int		push(t_stack *pile_a, t_stack *pile_b);
int		rotate(t_stack *pile);
int		rrotate(t_stack *pile);

#endif