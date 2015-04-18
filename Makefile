#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/15 16:52:46 by basle-qu          #+#    #+#              #
#    Updated: 2015/01/25 16:37:45 by basle-qu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRCS = main.c init.c print.c verif.c
OBJS = $(SRCS:.c=.o)
NAME = fdf
CFLAGS = -Wall -Wextra -Werror
LIB = -L /USR/X11/lib -lmlx -lXext -lX11 -L libft -lft

.PHONY: all test clean fclean re

all: $(NAME)

$(NAME):
	make re -C libft
	gcc -c -I includes $(CFLAGS) $(SRCS)
	gcc $(LIB) $(CFLAGS) $(OBJS) -o $(NAME)

test:
	gcc -c -I includes $(CFLAGS) $(SRCS)
	gcc $(LIB) $(CFLAGS) $(OBJS) -o $(NAME)
	make clean

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

cleanall: fclean
	make fclean -C libft/

re: fclean $(NAME)