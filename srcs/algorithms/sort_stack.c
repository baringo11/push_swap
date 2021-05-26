#include "../../includes/push_swap.h"

int		moves_rotation_b(t_stacks *stacks, int prev_nb, int next_nb, int len_b)
{
	t_lst	*aux;
	int		pos_next_nb;

	pos_next_nb = pos_in_list(stacks->b, next_nb);
	aux = stacks->b;
	if (prev_nb >= 0)
	{
		if (prev_nb > (len_b / 2))
		{
			stacks->moves_rb = len_b - prev_nb;
			return (0);
		}
		stacks->moves_rb = prev_nb;
		return (1);
	}
	aux = lstlast(stacks->b);
	while (aux->content != next_nb)
	{
		if (pos_next_nb >= (len_b / 2))
			operations(stacks, "rrb");
		else
			operations(stacks, "rb");
		aux = lstlast(stacks->b);
	}
	return (-1);
}

int		find_correct_pos_in_b(t_stacks *stacks, int len_b)
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
	if (len_b)
		return (moves_rotation_b(stacks, prev_nb, next_nb, len_b));
	return (-1);
}

void	find_less_moves_pb(t_stacks *stacks, int *list, int len)
{
	int		ra;
	int		rb;

	ra = find_min_moves_nb_chunk(stacks, stacks->a, list[len]);
	if (ra)
		stacks->nb_to_pushb = lst_pos_content(stacks->a, stacks->moves_ra);
	rb = find_correct_pos_in_b(stacks, lstsize(stacks->b));
	while (stacks->moves_ra > 0 && stacks->moves_rb > 0 && \
		((ra == 1 && rb == 1) || (ra == 0 && rb == 0)))
		rotate_both_stacks(stacks, ra, rb);
	while (stacks->moves_ra > 0 && stacks->moves_ra--)
	{
		if (ra)
			operations(stacks, "ra");
		else
			operations(stacks, "rra");
	}
	while (stacks->moves_rb > 0 && stacks->moves_rb--)
	{
		if (rb)
			operations(stacks, "rb");
		else
			operations(stacks, "rrb");
	}
	operations(stacks, "pb");
}

void	final_sort(t_stacks *stacks, int *list, int stack_len)
{
	int	i;

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
	nb_of_chunks = 5;
	if (stack_len > 100)
		nb_of_chunks = 10;
	cont = (stack_len / nb_of_chunks) + (stack_len % nb_of_chunks);
	i = 0;
	while(stacks->a)
	{
		if (i == (stack_len / nb_of_chunks) && cont < stack_len )
		{
			i = 0;
			cont += (stack_len / nb_of_chunks);
		}
		find_less_moves_pb(stacks, list, cont - 1);
		i++;
	}
	final_sort(stacks, list, stack_len);
}
