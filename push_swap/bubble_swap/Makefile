# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 19:37:57 by ethebaul          #+#    #+#              #
#    Updated: 2024/12/17 22:19:42 by ethebaul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_itoa.c \
	ft_strdup.c \
	load_stack.c

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

CFLAGS = -Wall -Wextra -Werror -MD -MP

CC = cc

NAME = push_swap

HEADERS = ./

all: $(NAME)

$(NAME): $(OBJS) Makefile
	cc $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@

-include $(DEPS)

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re