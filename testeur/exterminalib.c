/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exterminalib.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:57:53 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/13 06:22:59 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exterminalib.h"

int	main(void)
{
	signal(SIGWINCH, resize_screen);
	resize_screen(0);
	add_part(new_part(free_area, fill, new_area((t_point){0, 0}, (t_point){w.ws_row, w.ws_col}, ' ')));
	add_part(new_part(0, print_center, new_text(0, 0, "Welcome to Exterminalib")));
	//add_part(new_part(0, print_center, new_text(0, 1, "What do you want to test ?")));
	print_screen();
	while (1)
	{
		handle_input();
		resize_screen(0);
	}
	return (0);
}
