/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:20:13 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/12 23:39:36 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "exterminalib.h"

void	test_ft_isalnum(void)
{
	char	buffer[1024];
	int		read_value;
	int		value;

	printf("Enter a number to test ft_isalnum():\n");
	read_value = read(0, buffer, 1023);
	buffer[read_value] = 0;
	value = atoi(buffer);
	printf("ft_isalnum(%d) returned: %d\n", value, ft_isalnum(value));
	printf("isalnum(%d) returned: %d\n", value, isalnum(value));
}