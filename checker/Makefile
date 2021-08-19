# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/19 19:30:53 by jbaringo          #+#    #+#              #
#    Updated: 2021/08/19 19:30:54 by jbaringo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	checker
CC =	gcc
FLAGS = -c -Wall -Wextra -Werror
OBJS =	$(SRCS:.c=.o)
SRCS =	srcs/main.c srcs/read_instructions.c srcs/utils_checker.c  srcs/operations_checker.c \
		srcs/GNL/get_next_line.c \
		../srcs/check_arguments.c \
		../srcs/utils/utils.c ../srcs/utils/lst_utils.c ../srcs/utils/lst_utils_2.c

INC = -I. -I ../srcs/libft
LFT = -L ../srcs/libft -lft

checker: $(SRCS)
	make -C ../srcs/libft
	$(CC) $(FLAGS) $(SRCS)
	mkdir -p srcs/obj
	mv *.o srcs/obj
	gcc -o $(NAME) srcs/obj/*.o $(INC) $(LFT)

all: $(NAME)

clean:
	make clean -C ../srcs/libft
	rm -f $(OBJS)
	rm -f srcs/obj/*.o
	rm -f *.o

fclean: clean
	make fclean -C ../srcs/libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re