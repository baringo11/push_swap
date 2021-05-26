#include "../../includes/push_swap.h"

void	rotate_both_stacks(t_stacks *stacks, int ra, int rb)
{
	if (ra && rb)
		operations(stacks, "rr");
	else if (!ra && !rb)
		operations(stacks, "rrr");
	stacks->moves_ra--;
	stacks->moves_rb--;
}

int	*find_chunks(t_lst *stack, int *list, int len)
{
	t_lst	*aux;
	int		index;
	int		nb;

	list[0] = find_min_nb(stack);
	index = 1;
	while (index < len)
	{
		aux = stack;
		nb = __INT_MAX__;
		while (aux->next)
		{
			if (aux->content > list[index - 1] && aux->content < nb)
				nb = aux->content;
			aux = aux->next;
		}
		if (aux->content > list[index - 1] && aux->content < nb)
			nb = aux->content;
		list[index] = nb;
		index++;
	}
	return (list);
}

int	find_min_moves_nb_chunk(t_stacks *stacks, t_lst *stack, int max)
{
	int		i;
	int		top;
	int		bottom;

	top = -1;
	i = 0;
	while (stack)
	{
		if (stack->content <= max)
		{
			if (top == -1)
				top = i;
			bottom = i;
		}
		i++;
		stack = stack->next;
	}
	stacks->nb_to_pushb = lst_pos_content(stacks->a, bottom);
	bottom = i - bottom;
	if (top <= bottom)
		stacks->moves_ra = top;
	else
		stacks->moves_ra = bottom;
	return (top <= bottom);
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

int		pos_in_list(t_lst *stack, int n)
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
