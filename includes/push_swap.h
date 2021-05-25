#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
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
	int				cont;
}					t_stacks;

int		pos_in_list(t_lst *stack, int n);
int		find_min_nb(t_lst *stack);
int		find_min_moves_nb_chunk(t_lst *stack, int min, int max);

void	sort_stack(t_stacks *stacks, int stack_len);
void	sort_5(t_stacks *stacks);
void	sort_3(t_stacks *stacks);
int		check_if_sorted(t_lst *stack);
void	print_stacks(t_stacks *stacks);
void    sort(t_stacks *stacks);
void	operations(t_stacks *stacks, char *operations);
int		check_arguments(t_lst **stack_a, char **argv);

void	ft_rotate(t_lst **stack);
void	ft_reverse_rotate(t_lst **stack);

void	delete_last(t_lst **stack);
t_lst	*lstlast(t_lst *lst);
int		lstsize(t_lst *lst);
void	lstadd_back(t_lst **alst, t_lst *new);
int		list_lenght(t_lst *head);
void	lstadd_front(t_lst **alst, t_lst *new);
t_lst	*lstnew(int content);

void	exit_error(t_stacks *stacks);
void	clear_stacks(t_stacks *stacks);
void	*ft_free_matrix(char **matrix);


#endif