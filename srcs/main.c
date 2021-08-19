/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 19:27:32 by jbaringo          #+#    #+#             */
/*   Updated: 2021/08/19 19:43:02 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/*
valgrind --leak-check=full \
			--show-leak-kinds=all \
			--track-origins=yes \
			--verbose \
			--log-file=valgrind-out.txt \
			./push_swap
*/
void	check_if_final_sorted(t_lst *a)
{
	int	i;

	i = 0;
	while (a->next)
	{
		if (a->content > a->next->content)
		{
			i = 0;
			while (i++ < 10000)
				printf("ERROR INCORRECT SORT : n: %d in pos[%d]\n", a->content, i);
			break ;
		}
		i++;
		a = a->next;
	}
}

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
	if (argc < 2 || !check_arguments(&stacks.a, argv))
		return (0);
	if (check_if_sorted(stacks.a))
		return (0);
	if (argc == 4)
		sort_3(&stacks);
	else if (argc == 6)
		sort_5(&stacks);
	else
		sort_stack(&stacks, lstsize(stacks.a));
	check_if_final_sorted(stacks.a);
	clear_stacks(&stacks);
	return (0);
}
