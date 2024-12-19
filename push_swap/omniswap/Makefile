# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 19:37:57 by ethebaul          #+#    #+#              #
#    Updated: 2024/12/19 16:01:23 by ethebaul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = \
generator.c \
trainer.c \
print_state.c \
sort.c

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

CFLAGS = -Wall -Wextra -Werror -MD -MP

CC = cc

NAME = trainer

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