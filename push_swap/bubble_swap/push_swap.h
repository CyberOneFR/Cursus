/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:30:31 by ethebaul          #+#    #+#             */
/*   Updated: 2024/12/17 22:39:03 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*stack;
	int	size;
}	t_stack;

void	print_stack(t_stack *pile_a);
void	sort_stack(t_stack *pile_a);
void	sa(t_stack *pile_a);
void	ra(t_stack *pile_a);
void	rra(t_stack *pile_a);
char	*ft_strdup(const char *s);
char	*ft_itoa(int n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_atoi(const char *str);
t_stack	*stack_load(int size, char **elements);

#endif