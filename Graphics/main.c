/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 00:48:32 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/20 01:15:22 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>

int	main(int argc, char **argv)
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Event		event;
	int				quit;

	if (SDL_Init(SDL_INIT_VIDEO))
	{
		SDL_Log("Error: %s\n", SDL_GetError());
		return (EXIT_FAILURE);
	}
	SDL_Quit();
	return (EXIT_SUCCESS);
}
