/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shmup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 22:01:28 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/23 05:51:23 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"

int	main(void)
{
	t_env	env;

	env.win = initscr();
	env.height = 100;
	env.width = 100;
	env.quit = 1;
	env.context = shmup_init();
	if (!env.context)
	{
		endwin();
		printf("Error during initialization\n");
		return (1);
	}
	while (env.quit)
	{
		shmup_update(&env);
		render_context(&env);
	}
	endwin();
	return (0);
}

t_context	*shmup_init(void)
{
	t_context	*context;

	context = menu_init();
	if (!context)
		return (0);
	return (context);
}
