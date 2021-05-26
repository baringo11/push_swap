#include "../includes/push_swap.h"

int		lst_pos_content(t_lst *lst, int pos)
{
	while (lst && pos--)
		lst = lst->next;
	return (lst->content);
}

t_lst	*lstlast(t_lst *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
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

void	lstadd_back(t_lst **alst, t_lst *new)
{
	t_lst		*begin;

	if (!alst)
		*alst = lstnew(new->content);
	else
	{
		if (alst && new)
		{
			begin = *alst;
			if (begin == NULL)
				*alst = new;
			else
			{
				while (begin->next)
					begin = begin->next;
				begin->next = new;
			}
		}
	}
}

int	list_lenght(t_lst *head)
{
	t_lst	*tmp;
	int		i;

	if (head == NULL)
		return (0);
	tmp = head;
	printf("posicion %d lista: %d\n", 0, tmp->content);
	i = 1;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		printf("posicion %d lista: %d\n", i, tmp->content);
		i++;
	}
	return (i);
}

void	lstadd_front(t_lst **lst, t_lst *new)
{
	if (!lst)
		*lst = lstnew(new->content);
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

t_lst	*lstnew(int content)
{
	t_lst	*head;

	if (!(head = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	head->content = content;
	head->next = NULL;
	return (head);
}

void	delete_last(t_lst **stack)
{
	t_lst	*aux;
	t_lst	*delete;

	if (*stack)
	{
		aux = *stack;
		if (aux->next)
		{
			while (aux->next->next)
				aux = aux->next;
			delete = aux->next;
			aux->next = NULL;
			free(delete);
		}
		else
		{
			delete = aux;
			aux = NULL;
			free(delete);
			*stack = NULL;
		}
	}
}
