#include "../../includes/push_swap.h"

int	find_min_moves_nb_chunk(t_lst *stack, int min, int max)
{
	int		i;
	int		top;
	int		bottom;

	top = -1;
	i = 0;
	while (stack)
	{
		if (stack->content >= min && stack->content <= max)
		{
			if (top == -1)
				top = i;
			bottom = i;
		}
		i++;
		stack = stack->next;
	}
	bottom = i - bottom;
	if (top <= bottom)
		return (1);
	else
		return (0);
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
