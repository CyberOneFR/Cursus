/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:16:38 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/13 06:02:24 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exterminalib.h"

void	resize_screen(int sig)
{
	(void)sig;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	if (screen_buffer)
		free(screen_buffer);
	screen_buffer = malloc((w.ws_col * w.ws_row) * sizeof(char));
	print_screen();
}
