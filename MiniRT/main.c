/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:02:59 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/18 00:42:14 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/minirt.h"

int	main(void)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, 1920, 1080, "MiniRT");
	env->fps = 5;
	env->width = 1920;
	env->height = 1080;
	mlx_hook(env->win, ON_DESTROY, 0, exit_window, env);
	mlx_loop_hook(env->mlx, render, env);
	mlx_loop(env->mlx);
	return (0);
}

int	exit_window(t_env *env)
{
	mlx_destroy_window(env->mlx, env->win);
	exit(0);
	free(env);
	return (0);
}

int	render(t_env *env)
{
	clock_t	last_time;
	int		delta_time;

	last_time = clock();
	env->frame = mlx_new_image(env->mlx, env->width, env->height);
	render_frame(env);
	mlx_put_image_to_window(env->mlx, env->win, env->frame, 0, 0);
	mlx_destroy_image(env->mlx, env->frame);
	delta_time = (int)(clock() - last_time);
	printf("delta_time: %dms\n", delta_time / 1000);
	return (0);
}

void	render_frame(t_env *env)
{
	int	x;
	int	y;

	y = 0;
	while (y < env->height)
	{
		x = 0;
		while (x < env->width)
		{
			x++;
		}
		y++;
	}
}
