# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 23:53:19 by ethebaul          #+#    #+#              #
#    Updated: 2024/11/13 05:50:48 by ethebaul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I exterminalib.h

SRCS = exterminalib.c \
	important_functions/garbage_collector.c \
	important_functions/handle_input.c \
	objects_functions/add_part.c \
	objects_functions/del_part.c \
	objects_functions/free_area.c \
	objects_functions/free_text.c \
	objects_functions/last_part.c \
	objects_functions/new_area.c \
	objects_functions/new_part.c \
	objects_functions/new_text.c \
	print_functions/fill.c \
	print_functions/print_center.c \
	print_functions/print_left.c \
	print_functions/print_right.c \
	screen/free_screen.c \
	screen/print_screen.c \
	screen/resize_screen.c \
	utils/dictionary.c \
	utils/ft_strdup.c \
	utils/printable_len.c \
	

OBJS = $(SRCS:.c=.o)

NAME = exterminalib.out

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -g $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re