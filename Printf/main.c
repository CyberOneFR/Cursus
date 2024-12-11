/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:14:14 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/27 15:21:52 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char format[] = "Hello%cK";

	ft_printf(format, 1549);
	printf("\n");
	printf(format, 1549);
	return (0);
}
