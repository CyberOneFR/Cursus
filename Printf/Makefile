# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 19:37:57 by ethebaul          #+#    #+#              #
#    Updated: 2024/11/20 04:15:31 by ethebaul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c \
	ft_putargs_fd.c \

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

CFLAGS = -Wall -Wextra -Werror -MD -MP

CC = cc

NAME = libftprintf.a

HEADERS = ./headers/

LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) Makefile
	ar rcs $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	make -C ./libft

%.o: %.c
	$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@

-include $(DEPS)

clean:
	rm -f $(OBJS) $(DEPS)
	make -C ./libft clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean

re: fclean all

.PHONY : all clean fclean re