#include "../../includes/push_swap.h"

int lst_pos_content(t_lst *lst, int pos)
{
	while (lst && pos--)
		lst = lst->next;
	return (lst->content);
}

int lstsize(t_lst *lst)
{
	int		i;
	t_lst	*current;

	i = 0;
	current = lst;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}

int		check_if_sorted(t_lst *stack)
{
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}
