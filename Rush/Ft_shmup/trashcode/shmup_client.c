/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shmup_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 21:43:22 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/23 03:42:14 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"

int	shmup_client(void)
{
	t_env	env;

	while (1)
	{
		shmup_update(env)
		shmup_render(env);
	}
	return (0);
}
