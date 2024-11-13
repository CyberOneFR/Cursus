/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exterminalib.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:57:53 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/13 08:23:10 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exterminalib.h"

int	main(void)
{
	signal(SIGWINCH, resize_screen);
	signal(SIGINT, garbage_collector);
	add_part(new_part(0, print_center, new_text(0, 0, "Welcome to Exterminalibft")));
	add_part(new_part(0, print_center, new_text(0, 2, "What do you want to test ?")));
	add_part(new_part(free_text, print_center, new_text(0, 4, ft_strcat(ft_strcat(ft_itoa(w.ws_col), ft_str(" | ")), ft_itoa(w.ws_row)))));
	add_part(new_part(free_text, print_center, new_text(0, 5, ft_strcat(ft_strcat(ft_itoa(w.ws_col), ft_str(" | ")), ft_itoa(w.ws_row)))));
	resize_screen(0);
	while (1)
	{
		handle_input();
	}
	return (0);
}
