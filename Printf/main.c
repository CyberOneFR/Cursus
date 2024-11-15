/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 05:30:58 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/15 05:40:09 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	void	*ptr;

	ptr = malloc(42);
	ft_printf("%c_%s_%p_%d_%i_%u_%x_%X_%%_\n", 'T', "Hello", ptr, 42, 42, 42, 42, 42);
	printf("%c_%s_%p_%d_%i_%u_%x_%X_%%_\n", 'T', "Hello", ptr, 42, 42, 42, 42, 42);
	free(ptr);
	return (0);
}