#include "../includes/checker.h"

void	ft_swap(t_lst **stack)
{
	t_lst	*tmp;
	int		value1;
	int		value2;

	tmp = *stack;
	if (lstsize(tmp) > 1)
	{
		value1 = tmp->content;
		value2 = tmp->next->content;
		tmp->content = value2;
		tmp->next->content = value1;
		*stack = tmp;
	}
}

void	ft_push(t_stacks_checker *stacks, char c)
{
	t_lst	*tmp;

	if (c == 'a' && stacks->b)
	{
		lstadd_front(&stacks->a, lstnew(stacks->b->content));
		tmp = stacks->b;
		stacks->b = stacks->b->next;
		free (tmp);
	}
	else if (c == 'b' && stacks->a)
	{
		lstadd_front(&stacks->b, lstnew(stacks->a->content));
		tmp = stacks->a;
		stacks->a = stacks->a->next;
		free (tmp);
	}
}

void	ft_rotate(t_lst **stack)
{
	t_lst	*aux;
	t_lst	*tmp;

	tmp = *stack;
	if (lstsize(tmp) > 1)
	{
		lstadd_back(&tmp, lstnew(tmp->content));
		aux = tmp;
		tmp = tmp->next;
		free(aux);
		*stack = tmp;
	}
}

void	ft_reverse_rotate(t_lst **stack)
{
	t_lst	*aux;
	t_lst	*tmp;

	tmp = *stack;
	if (lstsize(tmp) > 1)
	{
		aux = lstlast(tmp);
		lstadd_front(&tmp, lstnew(aux->content));
		delete_last(&tmp);
		*stack = tmp;
	}
}

void	operations_checker(t_stacks_checker *stacks, char **operations)
{
	int		i;

	i = -1;
	while (operations[++i])
	{
		if (!ft_strncmp(operations[i], "sa", 3) || !ft_strncmp(operations[i], "ss", 3))
			ft_swap(&stacks->a);
		if (!ft_strncmp(operations[i], "sb", 3) || !ft_strncmp(operations[i], "ss", 3))
			ft_swap(&stacks->b);
		if (!ft_strncmp(operations[i], "pa", 3))
			ft_push(stacks, 'a');
		else if (!ft_strncmp(operations[i], "pb", 3))
			ft_push(stacks, 'b');
		if (!ft_strncmp(operations[i], "ra", 3) || !ft_strncmp(operations[i], "rr", 3))
			ft_rotate(&stacks->a);
		if (!ft_strncmp(operations[i], "rb", 3) || !ft_strncmp(operations[i], "rr", 3))
			ft_rotate(&stacks->b);
		if (!ft_strncmp(operations[i], "rra", 4) || !ft_strncmp(operations[i], "rrr", 4))
			ft_reverse_rotate(&stacks->a);
		if (!ft_strncmp(operations[i], "rrb", 4) || !ft_strncmp(operations[i], "rrr", 4))
			ft_reverse_rotate(&stacks->b);
	}
}
