/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shmup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 22:01:28 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/23 05:20:01 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"

int	main(int ac, char **av)
{
	t_env	env;

	env.win = initscr();
	env.height = 20;
	env.width = 20;
	env.context = 0;
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
		shmup_render(&env);
	}
	endwin();
	(void)ac;
	(void)av;
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
