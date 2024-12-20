/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:16:38 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/13 08:09:44 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exterminalib.h"

void	resize_screen(int sig)
{
	(void)sig;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	w.ws_row -= 1;
	if (screen_buffer)
		free(screen_buffer);
	screen_buffer = malloc((w.ws_col * w.ws_row) * sizeof(char));
	if (!screen_buffer)
		garbage_collector(ENOMEM);
	blank();
	replace_part(last_part(), new_part(free_text, print_center, new_text(0, 5, ft_strcat(ft_strcat(ft_itoa(w.ws_col), ft_str(" | ")), ft_itoa(w.ws_row)))));
	print_screen();
}
