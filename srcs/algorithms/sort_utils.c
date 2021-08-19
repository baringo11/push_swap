/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 19:28:27 by jbaringo          #+#    #+#             */
/*   Updated: 2021/08/19 19:40:04 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	check_number_of_moves(t_stacks *stacks, int ra, int rb)
{
	int	tmp_total_moves;
	int	total_moves;

	total_moves = stacks->moves_ra[1] + stacks->moves_rb[1];
	tmp_total_moves = stacks->tmp_moves_ra + stacks->tmp_moves_rb;
	if (ra == rb)
	{
		if (stacks->tmp_moves_ra < stacks->tmp_moves_rb)
			tmp_total_moves -= stacks->tmp_moves_ra;
		else
			tmp_total_moves -= stacks->tmp_moves_rb;
	}
	if (stacks->moves_ra[0] == stacks->moves_rb[0])
	{
		total_moves = stacks->moves_ra[1];
		if (stacks->moves_ra[1] < stacks->moves_rb[1])
			total_moves = stacks->moves_rb[1];
	}
	if (tmp_total_moves < total_moves)
	{
		stacks->moves_ra[0] = ra;
		stacks->moves_ra[1] = stacks->tmp_moves_ra;
		stacks->moves_rb[0] = rb;
		stacks->moves_rb[1] = stacks->tmp_moves_rb;
	}
}

void	rotate_both_stacks(t_stacks *stacks, int normal_rotation)
{
	if (normal_rotation == 1)
		operations(stacks, "rr");
	else if (normal_rotation == 0)
		operations(stacks, "rrr");
	stacks->moves_ra[1]--;
	stacks->moves_rb[1]--;
}

int	moves_stack_a(t_stacks *stacks, int len)
{
	int		i;

	stacks->nb_to_pushb = lst_pos_content(stacks->a, stacks->index);
	if (stacks->index > (len / 2))
	{
		i = len - stacks->index;
		stacks->tmp_moves_ra = i;
		return (0);
	}
	else
	{
		stacks->tmp_moves_ra = stacks->index;
		return (1);
	}
}

int	find_min_nb(t_lst *stack)
{
	int	min_nb;

	min_nb = stack->content;
	while (stack->next)
	{
		if (stack->content < min_nb)
			min_nb = stack->content;
		stack = stack->next;
	}
	if (stack->content < min_nb)
		min_nb = stack->content;
	return (min_nb);
}

int	pos_in_list(t_lst *stack, int n)
{
	int		i;

	i = 0;
	while (stack && stack->content != n)
	{
		i++;
		stack = stack->next;
	}
	if (!stack)
		return (-1);
	return (i);
}
