/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 05:30:58 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/16 14:53:48 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	void	*ptr;
	int		len1;
	int		len2;

	ptr = malloc(42);
	len1 = ft_printf("%c_%s_%p_%d_%i_%u_%x_%X_%%_\n", 'T', "Hello", ptr, 42, 42, 42, 42, 42);
	len2 = printf("%c_%s_%p_%d_%i_%u_%x_%X_%%_\n", 'T', "Hello", ptr, 42, 42, 42, 42, 42);
	free(ptr);
	printf("ft_printf: %d\n", len1);
	printf("printf: %d\n", len2);
	return (0);
}