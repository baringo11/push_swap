NAME =	push_swap
CC =	gcc
FLAGS = -c  -g #-Wall -Wextra -Werror
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


.PHONY: all clean fclean re

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
