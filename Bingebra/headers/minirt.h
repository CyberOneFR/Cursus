/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:21:24 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/21 19:05:26 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include <stdlib.h>
# include <time.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <math.h>
# include <complex.h>

# define THREADS 4
# define WIDTH 1920
# define RWIDTH 0.00052083333
# define HEIGHT	1080
# define RHEIGHT 0.00092592592
# define PI 3.14159265359

# define ON_DESTROY 17

typedef int		t_matrix[4][4];
typedef int		t_point[4];
typedef t_point	t_triangle[3];

typedef struct s_objects
{
	t_triangle			*triangle;
	struct s_objects	*next_obj;
}	t_objects;

typedef struct s_env
{
	void			*mlx;
	void			*win;
	int				bpp;
	int				bpl;
	int				bpe;
	void			*frame;
	void			*buf;
	int				width;
	int				height;
	double			dx;
	double			dy;
	double			factor;
}	t_env;

typedef struct s_thread_data
{
	t_env	*env;
	int		start_y;
	int		end_y;
}	t_thread_data;

int				exit_window(t_env *env);
int				render(t_env *env);
void			render_frame(t_env *env);
void			*render_frame_thread(void *data);
int				key_hook(int keycode, t_env *env);
int				mouse_hook(int button, int x, int y, t_env *env);
unsigned int	get_color(double x, double y, double factor, double dx, double dy);

#endif