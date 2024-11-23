/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   websocket.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:46:47 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/23 02:29:45 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSOCKET_H
# define WEBSOCKET_H

# include <netinet/in.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <arpa/inet.h>
# include <sha1.h>
# include <openssl/sha.h>
# include <fcntl.h>
# include <errno.h>
# include "base64.h"

typedef struct s_ws_server
{
	int					socket_fd;
	struct sockaddr_in	address;
}	t_ws_server;

typedef struct s_ws_client
{
	int					client_fd;
	struct sockaddr_in	client_address;
}	t_ws_client;

void	ws_init_server(t_ws_server *server, int port);
void	ws_accept_client(t_ws_server *server, t_ws_client *client);
void	ws_send_msg(t_ws_client *client, const char *message);
int		ws_receive_msg(t_ws_client *client, char *buffer, size_t buffer_size);
void	ws_handshake(t_ws_client *client);

#endif