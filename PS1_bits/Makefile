# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/03 11:58:56 by bmota-si          #+#    #+#              #
#    Updated: 2023/08/18 14:44:37 by bmota-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = new.c insert.c print.c simple_sort.c get.c commands/push.c commands/swap.c  \
			commands/rotate.c commands/reverserotate.c lstsize.c array.c utils.c \

CC = cc -g
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean: clean
				$(RM) $(NAME)

re: fclean all