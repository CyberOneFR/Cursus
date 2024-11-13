/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 05:15:42 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/13 05:22:16 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exterminalib.h"

void	garbage_collector(int err)
{
	if (screen_buffer)
		free(screen_buffer);
	free_screen();
	errno = err;
	perror(strerror(errno));
	exit(1);
}
