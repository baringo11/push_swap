#include "../../includes/push_swap.h"

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

int		find_correct_position(t_stacks *stacks, int nb, int len_b)
{
	t_lst	*aux;
	int		prev_nb;
	int		next_nb;

	aux = stacks->b;
	prev_nb = -2147483648;
	next_nb = __INT_MAX__;
	while (aux)
	{
		if (prev_nb < aux->content && aux->content < nb)
			prev_nb = aux->content;
		if (next_nb > aux->content && aux->content > nb)
			next_nb = aux->content;
		aux = aux->next;
	}
	prev_nb = pos_in_list(stacks->b, prev_nb);
	//next_nb = pos_in_list(stacks->b, next_nb);
	if (prev_nb >= 0)
	{
		if (len_b && prev_nb > (len_b / 2))
		{
			prev_nb = len_b - prev_nb;
			while (prev_nb--)
				operations(stacks, "rrb");
		}
		else
			while (prev_nb--)
				operations(stacks, "rb");
	}
	else if (pos_in_list(stacks->b, next_nb) != -1)
	{
		while (1)
		{
			aux = lstlast(stacks->b);
			if (aux->content != next_nb)
				operations(stacks, "rb");
			else
				break;
		}
	}
}

void	find_less_moves_chunk(t_stacks *stacks, int *list, int len)
{
	int		normal_rotation;

	normal_rotation = find_min_chunk(stacks->a, list[0], list[len]);
	if (normal_rotation)
	{
		while (stacks->a)
		{
			if (stacks->a->content >= list[0] && stacks->a->content <= list[len])
				return ;
			operations(stacks, "ra");
		}
	}
	else
	{
		while (stacks->a)
		{
			if (stacks->a->content >= list[0] && stacks->a->content <= list[len])
				return ;
			operations(stacks, "rra");
		}
	}
}

void	sort_stack(t_stacks *stacks, int stack_len)
{
	int	*list;
	int	i;
	int	nb_of_chunks;
	int	cont;

	list = (int *)malloc(sizeof(int) * stack_len);
	if (!list)
		exit_error(stacks);
	list = find_chunks(stacks->a, list, stack_len);
	i = 0;
	nb_of_chunks = 5;
	cont = (stack_len / nb_of_chunks) + (stack_len % nb_of_chunks);
	while(stacks->a)
	{
		if (i == (stack_len / nb_of_chunks) && cont < stack_len )
		{
			i = 0;
			cont += (stack_len / nb_of_chunks);
		}
		find_less_moves_chunk(stacks, list, cont - 1);
		find_correct_position(stacks, stacks->a->content, lstsize(stacks->b));
		operations(stacks, "pb");
		i++;
	}
	i = pos_in_list(stacks->b, list[0]);
	if (i > (stack_len / 2))
	{
		i = stack_len - i;
		i--;
		while (i--)
			operations(stacks, "rrb");
	}
	else
		while (i--)
			operations(stacks, "rb");
	while (stacks->b)
		operations(stacks, "pa");
}
