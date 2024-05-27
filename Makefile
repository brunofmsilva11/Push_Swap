# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/03 11:58:56 by bmota-si          #+#    #+#              #
#    Updated: 2023/08/30 11:50:11 by bmota-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = array.c check.c free.c get.c main.c push_swap.c simple_sort.c utils.c verification.c \
			commands/push.c commands/swap.c commands/rotate.c commands/reverserotate.c \

CC = cc -g
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT = ./libft/libft.a

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(NAME): $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
			$(MAKE) clean -C libft
			$(RM) $(OBJS)

fclean: clean
				$(MAKE) clean -C libft
				$(RM) $(NAME)

re: fclean all