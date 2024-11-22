/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shmup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 21:44:52 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/23 00:40:38 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHMUP_H
# define SHMUP_H

# include <stdlib.h>
# include <ncurses.h>

struct s_players
{
	int			x;
	int			y;
	int			life;
	int			score;
};
typedef struct s_players	t_players;
struct	s_scene
{
	t_players	**players;
	//t_enemies	**enemies;
	//t_bullets	**bullets;
};
typedef struct s_scene		t_scene;
struct s_server
{
	int			port;
	int			sock;
	t_scene		*scene;
};
typedef struct s_server		t_server;

int	shmup_server(void);
int	shmup_client(void);

#endif