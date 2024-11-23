/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shmup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 21:44:52 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/23 06:40:56 by ethebaul         ###   ########.fr       */
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
	t_element		*elements;
	t_selectable	*selectable;
	int				type;
}	t_context;
typedef struct s_element
{
	t_point				p1;
	t_point				p2;
	char				c;
	NCURSES_ATTR_T		attr;
	NCURSES_COLOR_T		color;
	void				*data;
	void				(*render)(); //for rendering data or other things
	void				(*del)(); //for deleting data if needed
	void				(*action)(); //for action on element like button
	struct s_element	*next;
}	t_element;
typedef struct s_selectable
{
	t_element		*elements;
	t_element		*up;//element up from this one for menu naviguation
	t_element		*down;//same for down
	t_element		*left;//same for left
	t_element		*right;//same for right
}	t_selectable;
typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

t_context	*shmup_init(void);

void		update(t_env *env);
void		handle_menu_input(t_env *env);
void		handle_game_input(t_env *env);

void		render_context(t_env *env);//draw each element in the context
void		free_context(t_env *env, t_context *new_context);//free the context

void		draw(int x, int y, char c);//draw a char at x, y
void		text_draw(t_element *element);//draw data as a string from p1
void		draw_element(t_element *element);//draw the element and its data
void		fill(t_point p1, t_point p2, char c);//fill a rectangle with char c

t_element	*element_init(void);//return a new declared element
t_element	*last_element(t_element *element);//return lst element of the list

t_context	*menu_init(void);//initialize a menu context like an assets

#endif