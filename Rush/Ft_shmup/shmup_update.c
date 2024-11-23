/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shmup_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 03:55:10 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/23 04:59:16 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"

void	shmup_update(t_env *env)
{
	int	key;

	key = getch();
	if ((env->context)->type == 1)
	{
		//update_menu(env); for animation or other stuff to update
		handle_menu_input(env, key);//for menu navigation
	}
	if ((env->context)->type == 2)
	{
		//update_game(env);  update enemies, bullets, animations or other stuff
		handle_game_input(env, key);
	}
}

void	update_menu(t_env *env, int key)
{
	if (key == KEY_UP)
		(env->context)->selectable = (env->context)->selectable->up;
	if (key == KEY_DOWN)
		(env->context)->selectable = (env->context)->selectable->down;
	if (key == KEY_LEFT)
		(env->context)->selectable = (env->context)->selectable->left;
	if (key == KEY_RIGHT)
		(env->context)->selectable = (env->context)->selectable->right;
	if (key == 10)
		(env->context)->selectable->elements->\
			action(env, (env->context)->selectable->elements);
}
//move the player shoot and pause the game

void	handle_input(t_env *env, int key)
{
	if (key == KEY_UP)
		;
	if (key == KEY_DOWN)
		;
	if (key == KEY_LEFT)
		;
	if (key == KEY_RIGHT)
		;
	if (key == ' ')
		;
	if (key == 27)
		;
}
