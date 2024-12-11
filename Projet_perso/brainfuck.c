/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:04:03 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/29 10:34:24 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	brainfuck(char *code);
void	bzero(void *s, size_t n);

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			brainfuck(argv[i]);
			i++;
		}
	}
	return (0);
}

void	brainfuck(char *code)
{
	char	buffer[2048];
	char	*ptr;

	ptr = buffer;
	bzero(buffer, sizeof(buffer));
	while (*code)
	{
		if (*code == '>')
			ptr++;
		else if (*code == '<')
			ptr--;
		else if (*code == '+')
			(*ptr)++;
		else if (*code == '-')
			(*ptr)--;
		else if (*code == '.')
			write(1, ptr, 1);
		else if (*code == ',')
			read(0, ptr, 1);
		else if (*code == '[')
		{
			if (!*ptr)
				while (*code != ']')
					code++;
		}
		else if (*code == ']')
		{
			if (*ptr)
				while (*code != '[')
					code--;
		}
		code++;
	}
}

void	bzero(void *s, size_t n)
{
	char	*ptr;

	ptr = s;
	while (n--)
		*ptr++ = 0;
}
