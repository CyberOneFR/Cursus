/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:21:24 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/18 00:40:01 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include <stdlib.h>
# include <time.h>
# include <unistd.h>
# include <stdio.h>

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
	void		*mlx;
	void		*win;
	void		*frame;
	int			fps;
	int			width;
	int			height;
	int			fov;
	t_point		*origin;
	t_objects	*scene;
}	t_env;

int		exit_window(t_env *env);
int		render(t_env *env);
void	render_frame(t_env *env);

#endif