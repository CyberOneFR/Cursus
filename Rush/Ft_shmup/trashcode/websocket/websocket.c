/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   websocket.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:49:24 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/23 03:25:13 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "websocket.h"

void	ws_init_server(t_ws_server *server, int port)
{
	int	flags;

	server->socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server->socket_fd == -1)
	{
		printf("Error: socket creation failed\n");
		exit(EXIT_FAILURE);
	}
	flags = fcntl(server->socket_fd, F_GETFL, 0);
	if (flags == -1)
	{
		printf("Error: fcntl F_GETFL failed\n");
		close(server->socket_fd);
		exit(EXIT_FAILURE);
	}
	if (fcntl(server->socket_fd, F_SETFL, flags | O_NONBLOCK) == -1)
	{
		printf("Error: fcntl F_SETFL failed\n");
		close(server->socket_fd);
		exit(EXIT_FAILURE);
	}
	server->address.sin_family = AF_INET;
	server->address.sin_addr.s_addr = INADDR_ANY;
	server->address.sin_port = htons(port);
	if (bind(server->socket_fd, \
		(struct sockaddr *)&server->address, sizeof(server->address)) == -1)
	{
		printf("Error: bind failed\n");
		close(server->socket_fd);
		exit(EXIT_FAILURE);
	}
	if (listen(server->socket_fd, 10) == -1)
	{
		printf("Error: listen failed\n");
		close(server->socket_fd);
		exit(EXIT_FAILURE);
	}
}

void	ws_accept_client(t_ws_server *server, t_ws_client *client)
{
	socklen_t	client_len;

	client_len = sizeof(client->client_address);
	client->client_fd = -1;
	while (client->client_fd == -1)
	{
		client->client_fd = accept(server->socket_fd, \
		(struct sockaddr *)&client->client_address, &client_len);
		if (errno != EWOULDBLOCK && errno != EAGAIN)
		{
			printf("Error: accept failed\n");
			close(server->socket_fd);
			exit(EXIT_FAILURE);
		}
	}
}

void	ws_send_msg(t_ws_client *client, const char *message)
{
	send(client->client_fd, message, strlen(message), 0);
}

int	ws_receive_msg(t_ws_client *client, char *buffer, size_t buffer_size)
{
	int	readsize;

	readsize = recv(client->client_fd, buffer, buffer_size - 1, 0);
	buffer[readsize] = '\0';
	return (readsize);
}

void	ws_handshake(t_ws_client *client)
{
	unsigned char	hash[SHA_DIGEST_LENGTH];
	char			buffer[1024];
	char			accept_key[29];
	char			response[256];
	char			*key;

	ws_receive_msg(client, buffer, sizeof(buffer));
	key = strstr(buffer, "Sec-WebSocket-Key: ");
	*(strstr((key + 19), "\r\n")) = '\0';
	strcat((key + 19), "258EAFA5-E914-47DA-95CA-C5AB0DC85B11");
	SHA1((unsigned char *)key, strlen(key), hash);
	base64_encode(hash, SHA_DIGEST_LENGTH, accept_key);
	snprintf(response, sizeof(response), \
			"HTTP/1.1 101 Switching Protocols\r\n"\
			"Upgrade: websocket\r\n"\
			"Connection: Upgrade\r\n"\
			"Sec-WebSocket-Accept: %s\r\n\r\n", \
			accept_key);
	ws_send_msg(client, response);
}
