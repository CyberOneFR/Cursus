# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 19:37:57 by ethebaul          #+#    #+#              #
#    Updated: 2024/11/19 22:03:55 by ethebaul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

HEADERS = ./headers/

LIBS = ./mlx_linux/libmlx.a -lbsd -lXext -lX11 -lm


CFLAGS = -MD -MP

CC = cc

NAME = MiniRT.exe

all: $(NAME)

$(NAME): $(OBJS) Makefile
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@

-include $(DEPS)

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re