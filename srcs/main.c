/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 19:27:32 by jbaringo          #+#    #+#             */
/*   Updated: 2021/09/11 19:47:43 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	initializate_variables(t_stacks *stacks)
{
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->nb_to_pushb = 0;
	stacks->tmp_moves_ra = -1;
	stacks->tmp_moves_rb = -1;
	stacks->moves_ra[0] = 0;
	stacks->moves_ra[1] = 1000000;
	stacks->moves_rb[0] = 0;
	stacks->moves_rb[1] = 1000000;
	errno = 0;
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	initializate_variables(&stacks);
	if (argc < 2 || !check_arguments(&stacks.a, argv) || \
		check_if_sorted(stacks.a))
	{
		clear_stacks(&stacks);
		return (0);
	}
	if (argc == 4)
		sort_3(&stacks);
	else if (argc == 6)
		sort_5(&stacks);
	else
		sort_stack(&stacks, lstsize(stacks.a));
	clear_stacks(&stacks);
	return (0);
}
