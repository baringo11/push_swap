/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 19:30:37 by jbaringo          #+#    #+#             */
/*   Updated: 2021/08/19 19:55:32 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../srcs/GNL/get_next_line.h"
# include "../../includes/push_swap.h"

typedef struct s_stacks_checker
{
	struct s_lst	*a;
	struct s_lst	*b;
}					t_stacks_checker;

void	clear_stacks_checker(t_stacks_checker *stacks);
char	**add_new_pos_matrix(char **matrix, char *new);
int		read_instructions(t_stacks_checker *stacks);
void	operations_checker(t_stacks_checker *stacks, char **operations);

#endif