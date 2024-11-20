/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:02:59 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/20 00:28:42 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/minirt.h"

int	main(void)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "MiniRT");
	env->bpp = 32;
	env->bpl = WIDTH * 4;
	env->bpe = 0;
	env->dx = 0;
	env->dy = 0;
	env->factor = 1;
	env->frame = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->buf = mlx_get_data_addr(env->frame, &env->bpp, &env->bpl, &env->bpe);
	mlx_hook(env->win, ON_DESTROY, 0, exit_window, env);
	mlx_key_hook(env->win, key_hook, env);
	mlx_mouse_hook(env->win, mouse_hook, env);
	mlx_loop_hook(env->mlx, render, env);
	mlx_loop(env->mlx);
	return (0);
}

int	key_hook(int keycode, t_env *env)
{
	if (keycode == 97)
		env->dx += (HEIGHT * env->factor) * 0.1;
	else if (keycode == 100)
		env->dx -= (HEIGHT * env->factor) * 0.1;
	else if (keycode == 115)
		env->dy -= (HEIGHT * env->factor) * 0.1;
	else if (keycode == 119)
		env->dy += (HEIGHT * env->factor) * 0.1;
	return (1);
}

int	mouse_hook(int button, int x, int y, t_env *env)
{
	if (button == 4)
		env->factor *= 1.1;
	else if (button == 5)
		env->factor *= 0.9;
	return (1);
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
	render_frame(env);
	mlx_put_image_to_window(env->mlx, env->win, env->frame, 0, 0);
	delta_time = (int)(clock() - last_time);
	printf("delta_time: %dms\n", delta_time / 1000);
	return (0);
}

void	render_frame(t_env *env)
{
	pthread_t		threads[THREADS];
	t_thread_data	thread_data[THREADS];
	int				i;

	i = 0;
	while (i < THREADS)
	{
		thread_data[i].env = env;
		thread_data[i].start_y = i * (HEIGHT / THREADS);
		thread_data[i].end_y = (i + 1) * (HEIGHT / THREADS);
		pthread_create(&threads[i], NULL, render_frame_thread, &thread_data[i]);
		i++;
	}

	i = 0;
	while (i < THREADS)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}

void	*render_frame_thread(void *data)
{
	t_env			*env;
	double			factor;
	double			dx;
	double			dy;
	int				x;
	int				y;

	env = ((t_thread_data *)data)->env;
	factor = env->factor;
	dx = env->dx;
	dy = env->dy;
	y = ((t_thread_data *)data)->start_y;
	while (y < ((t_thread_data *)data)->end_y)
	{
		x = 0;
		while (x < WIDTH)
		{
			((unsigned int *)env->buf)[(y * WIDTH) + x] = get_color(x, y, dx, dy, factor);
			x++;
		}
		y++;
	}
	return (NULL);
}

unsigned int	get_color(double x, double y, double dx, double dy, double factor)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	double complex	c;
	double complex	z;
	int				iter;

	iter = 0;
	z = 0;
	x -= (WIDTH * 0.5) + dx;
	y -= (HEIGHT * 0.5) + dy;
	c = ((x / (HEIGHT * 0.5 * factor)) + ((y / (HEIGHT * 0.5 * factor)) * I));
	while (iter < 256)
	{
		z = (z * z) + c;
		if (cabs(z) > 2)
			break ;
		iter++;
	}
	r = (unsigned char)(iter & 255);
	g = (unsigned char)((iter * 2) & 255);
	b = (unsigned char)((iter * 3) & 255);
	return ((r << 16) | (g << 8) | b);
}
