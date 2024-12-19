# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 19:37:57 by ethebaul          #+#    #+#              #
#    Updated: 2024/12/19 13:55:18 by ethebaul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c \
bfs_sort.c \
stack/stack.c \
queue/queue.c \
inst/inst.c \
inst/isulss.c \
inst/inst_utils.c \
inst/swap.c \
inst/push.c \
inst/rotate.c \
parsing/ft_atoi.c \
parsing/ft_calloc.c \
parsing/ft_itoa.c \
parsing/ft_memove.c \
parsing/ft_strdup.c \
parsing/load.c

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
	@rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re