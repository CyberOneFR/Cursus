/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recherches.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:08:02 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/14 14:32:19 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	binary_print(unsigned long long nbr);

int	main(int argc, char **argv)
{
	if (argc <= 1)
		return (1);
	printf("%s\n", argv[1]);
	printf("%d\n", 5 % 3);
	binary_print(atoll(argv[1]));
	return (0);
}

void	binary_print(unsigned long long nbr)
{
	int		i;
	unsigned long long		div;

	i = 0;
	div = 2;
	while (i < 32)
	{
		printf("%d", (nbr % div) != 0);
		div *= 2;
		i++;
	}
}
