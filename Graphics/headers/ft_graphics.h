/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphics.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:10:00 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/21 19:12:03 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GRAPHICS_H
# define FT_GRAPHICS_H

# include <SDL2/SDL.h>

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_app
{
	SDL_Renderer	*renderer;
	SDL_Window		*window;
}	t_app;

#endif