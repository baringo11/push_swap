# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/19 19:30:56 by jbaringo          #+#    #+#              #
#    Updated: 2021/08/19 19:30:57 by jbaringo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap
CC =	gcc
FLAGS = -c  -Wall -Wextra -Werror
OBJS =	$(SRCS:.c=.o)
SRCS =	srcs/main.c srcs/check_arguments.c srcs/operations.c  \
		srcs/algorithms/sort_5.c srcs/algorithms/sort_3.c srcs/algorithms/sort_stack.c srcs/algorithms/sort_utils.c \
		srcs/utils/utils.c srcs/utils/lst_utils.c srcs/utils/lst_utils_2.c
INC = -I. -I srcs/libft
LFT = -L srcs/libft -lft

push_swap: $(SRCS)
	make -C srcs/libft
	$(CC) $(FLAGS) $(SRCS)
	mkdir -p srcs/obj
	mv *.o srcs/obj
	gcc -o $(NAME) srcs/obj/*.o $(INC) $(LFT)

all: $(NAME)

clean:
	make clean -C srcs/libft
	rm -f $(OBJS)
	rm -f srcs/obj/*.o
	rm -f *.o

fclean: clean
	make fclean -C srcs/libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
