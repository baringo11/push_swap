/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 19:28:05 by jbaringo          #+#    #+#             */
/*   Updated: 2021/08/19 19:28:06 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_lst	*lstlast(t_lst *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
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
