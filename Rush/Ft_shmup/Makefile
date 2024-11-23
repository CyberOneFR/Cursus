# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 19:37:57 by ethebaul          #+#    #+#              #
#    Updated: 2024/11/23 03:47:16 by ethebaul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADERS = ./headers/
SRCS =	./shmup.c \

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

CC = cc
CFLAGS = -Wall -Wextra -Werror -MD -MP
LIB = -lncurses

NAME = shmup.exe

all: $(NAME)

$(NAME): $(OBJS) Makefile
	$(CC) $(CFLAGS) $(LIB) -I $(HEADERS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@

-include $(DEPS)

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re