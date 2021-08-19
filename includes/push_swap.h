/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 19:30:30 by jbaringo          #+#    #+#             */
/*   Updated: 2021/08/19 19:30:31 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int				nb_to_pushb;
	int				moves_ra[2];
	int				tmp_moves_ra;
	int				moves_rb[2];
	int				tmp_moves_rb;
	int				index;
}					t_stacks;

void	operations(t_stacks *stacks, char *operations);
int		check_arguments(t_lst **stack_a, char **argv);

/* algorithms */
void	sort_3(t_stacks *stacks);
void	sort_5(t_stacks *stacks);
void	sort_stack(t_stacks *stacks, int stack_len);

/* utils_sort */
void	check_number_of_moves(t_stacks *stacks, int ra, int rb);
void	rotate_both_stacks(t_stacks *stacks, int normal_rotation);
int		moves_stack_a(t_stacks *stacks, int len);
int		find_min_nb(t_lst *stack);
int		pos_in_list(t_lst *stack, int n);

/* lst utils */
int		lst_pos_content(t_lst *lst, int pos);
int		lstsize(t_lst *lst);
int		check_if_sorted(t_lst *stack);
t_lst	*lstlast(t_lst *lst);
void	lstadd_back(t_lst **alst, t_lst *new);
void	lstadd_front(t_lst **alst, t_lst *new);
t_lst	*lstnew(int content);
void	delete_last(t_lst **stack);

/* utils */
void	ft_putstr_newline_fd(char *s1, int fd);
void	exit_error(t_stacks *stacks);
void	clear_stacks(t_stacks *stacks);
void	*ft_free_matrix(char **matrix);

#endif