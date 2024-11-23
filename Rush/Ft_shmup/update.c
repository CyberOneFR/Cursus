/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shmup_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 03:55:10 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/23 06:38:35 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"

void	update(t_env *env)
{
	if ((env->context)->type == 1)
	{
		//update_menu(env); for animation or other stuff to update
		handle_menu_input(env);//for menu navigation
	}
	if ((env->context)->type == 2)
	{
		//update_game(env);  update enemies, bullets, animations or other stuff
		handle_game_input(env);//for game controls
	}
}

void	handle_menu_input(t_env *env)
{
	int	key;

	key = getch();
	if (key == KEY_UP && (env->context)->selectable->up)//move the selection up if possible
		(env->context)->selectable = (env->context)->selectable->up;
	if (key == KEY_DOWN && (env->context)->selectable->down)//same for down
		(env->context)->selectable = (env->context)->selectable->down;
	if (key == KEY_LEFT && (env->context)->selectable->left)//same for left
		(env->context)->selectable = (env->context)->selectable->left;
	if (key == KEY_RIGHT && (env->context)->selectable->right)//same for right
		(env->context)->selectable = (env->context)->selectable->right;
	if (key == 10)//enter to activate the button or function associated to this element
		(env->context)->selectable->elements->\
			action(env, (env->context)->selectable->elements);
}
//move the player shoot and pause the game

void	handle_game_input(t_env *env)
{
	int	key;

	key = getch();
	if (key == KEY_UP)
		;//move the player up
	if (key == KEY_DOWN)
		;//same for down
	if (key == KEY_LEFT)
		;//same for left
	if (key == KEY_RIGHT)
		;//same for right
	if (key == ' ')
		;//space to shoot
	if (key == 27)
		;//escape to pause the game
}
