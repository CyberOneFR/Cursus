/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:14:14 by ethebaul          #+#    #+#             */
/*   Updated: 2024/12/11 15:59:46 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char format[] = "Hello%cK";
	char *str = "World!";

	ft_printf(format, str);
	printf("\n");
	printf(format, str);
	return (0);
}
