/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 19:28:22 by jbaringo          #+#    #+#             */
/*   Updated: 2021/08/19 19:39:36 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	moves_stack_b_2(t_stacks *stacks, int prev_pos, int next_pos, int len_b)
{
	if (prev_pos >= 0)
	{
		if (prev_pos > (len_b / 2))
		{
			stacks->tmp_moves_rb = len_b - prev_pos;
			return (0);
		}
		stacks->tmp_moves_rb = prev_pos;
		return (1);
	}
	if (next_pos >= 0)
	{
		if (next_pos >= (len_b / 2))
		{
			stacks->tmp_moves_rb = len_b - next_pos;
			stacks->tmp_moves_rb--;
			return (0);
		}
		stacks->tmp_moves_rb = next_pos;
		stacks->tmp_moves_rb++;
		return (1);
	}
	stacks->tmp_moves_rb = 0;
	return (1);
}

int	moves_stack_b(t_stacks *stacks, int len_b)
{
	t_lst	*aux;
	int		prev_nb;
	int		next_nb;

	aux = stacks->b;
	prev_nb = -2147483648;
	next_nb = __INT_MAX__;
	while (aux)
	{
		if (prev_nb < aux->content && aux->content < stacks->nb_to_pushb)
			prev_nb = aux->content;
		if (next_nb > aux->content && aux->content > stacks->nb_to_pushb)
			next_nb = aux->content;
		aux = aux->next;
	}
	prev_nb = pos_in_list(stacks->b, prev_nb);
	next_nb = pos_in_list(stacks->b, next_nb);
	return (moves_stack_b_2(stacks, prev_nb, next_nb, len_b));
}

void	do_pb(t_stacks *stacks)
{
	while (stacks->moves_ra[1] > 0 && stacks->moves_ra[1]--)
	{
		if (stacks->moves_ra[0])
			operations(stacks, "ra");
		else
			operations(stacks, "rra");
	}
	while (stacks->moves_rb[1] > 0 && stacks->moves_rb[1]--)
	{
		if (stacks->moves_rb[0])
			operations(stacks, "rb");
		else
			operations(stacks, "rrb");
	}
	operations(stacks, "pb");
}

void	find_less_moves_pb(t_stacks *stacks, int len, int i)
{
	int		ra;
	int		rb;

	stacks->nb_to_pushb = 0;
	stacks->index = 0;
	while (i < len)
	{
		ra = moves_stack_a(stacks, lstsize(stacks->a));
		rb = moves_stack_b(stacks, lstsize(stacks->b));
		check_number_of_moves(stacks, ra, rb);
		if ((stacks->moves_ra[1] == 0 && stacks->moves_rb[1] == 0) || \
			((stacks->moves_ra[1] + stacks->moves_rb[1]) == 1))
			break ;
		stacks->index++;
		i++;
	}
	while (stacks->moves_ra[1] > 0 && stacks->moves_rb[1] > 0 && \
			stacks->moves_ra[0] == stacks->moves_rb[0])
		rotate_both_stacks(stacks, stacks->moves_ra[0]);
	do_pb(stacks);
}

void	sort_stack(t_stacks *stacks, int stack_len)
{
	int	i;

	i = 0;
	while (stacks->a)
	{
		find_less_moves_pb(stacks, stack_len, i);
		stacks->moves_ra[1] = 1000000;
		stacks->moves_rb[1] = 1000000;
		i++;
	}
	i = pos_in_list(stacks->b, find_min_nb(stacks->b));
	if (i > (stack_len / 2))
	{
		i = stack_len - (i + 1);
		while (i--)
			operations(stacks, "rrb");
	}
	else
	{
		i++;
		while (i--)
			operations(stacks, "rb");
	}
	while (stacks->b)
		operations(stacks, "pa");
}
