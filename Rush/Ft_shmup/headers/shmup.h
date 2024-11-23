/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shmup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 21:44:52 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/23 05:14:14 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHMUP_H
# define SHMUP_H

# include <stdlib.h>
# include <time.h>
# include <ncurses.h>

typedef struct s_env
{
	WINDOW		*win;
	int			quit;
	int			height;
	int			width;
	t_context	*context;
}	t_env;
typedef struct s_context
{
	t_elements		*elements;
	t_selectable	*selectable;
	int				type;
}	t_context;
typedef struct s_elements
{
	t_point				p1;
	t_point				p2;
	char				c;
	void				*data;
	void				(*render)();
	NCURSES_ATTR_T		attr;
	NCURSES_COLOR_T		color;
	void				(*action)();
	struct s_elements	*next;
}	t_elements;
typedef struct s_selectable
{
	t_elements		*elements;
	t_elements		*up;//element up from this one for menu naviguation
	t_elements		*down;//same for down
	t_elements		*left;//same for left
	t_elements		*right;//same for right
}	t_selectable;
typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

#endif