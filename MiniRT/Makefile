# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 19:37:57 by ethebaul          #+#    #+#              #
#    Updated: 2024/11/16 18:16:46 by ethebaul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c

OBJS = $(SRCS:.c=.o)

HEADERS = ./headers/

LIBS = ./mlx_linux/libmlx.a -lXext -lX11 -lm -lbsd -L./libft -lXext -lX11 -lm


CFLAGS = -Wall -Wextra -Werror -fPIC

CC = cc

NAME = MiniRT.exe

all: $(NAME)

$(NAME): $(OBJS) Makefile
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re