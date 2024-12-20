/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 00:48:32 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/21 19:26:37 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graphics.h"

int	main(int argc, char **argv)
{
	t_app			t_app;

	(void)argc;
	(void)argv;
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		SDL_Log("Error: %s\n", SDL_GetError());
		return (EXIT_FAILURE);
	}
	t_app.window = SDL_CreateWindow("Graphics", 0, 0, WIDTH, HEIGHT, 0);
	if (!t_app.window)
	{
		printf("Error window: %s\n", SDL_GetError());
		exit(1);
	}
	SDL_Quit();
	return (EXIT_SUCCESS);
}
