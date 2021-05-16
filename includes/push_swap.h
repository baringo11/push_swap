#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "../srcs/libft/libft.h"

typedef struct		s_lst
{
	int				content;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_stacks
{
	struct s_lst	*a;
	struct s_lst	*b;
}					t_stacks;

void	operations(t_stacks *stacks, char *name);
int		check_arguments(t_lst **stack_a, char **argv);

void	delete_last(t_lst **stack);
t_lst	*lstlast(t_lst *lst);
int		lstsize(t_lst *lst);
void	lstadd_back(t_lst **alst, t_lst *new);
int		list_lenght(t_lst *head);
void	lstadd_front(t_lst **alst, t_lst *new);
t_lst	*lstnew(int content);

void	clear_stacks(t_stacks *stacks);
void	*ft_free_matrix(char **matrix);


#endif