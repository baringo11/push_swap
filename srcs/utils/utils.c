/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 19:28:08 by jbaringo          #+#    #+#             */
/*   Updated: 2021/09/11 19:54:59 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_putstr_newline_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", fd);
}

void	exit_error(t_stacks *stacks)
{
	clear_stacks(stacks);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
}

void	clear_stacks(t_stacks *stacks)
{
	if (stacks->a)
	{
		while (stacks->a->next)
			delete_last(&stacks->a);
		delete_last(&stacks->a);
	}
	if (stacks->b)
	{
		while (stacks->b->next)
			delete_last(&stacks->b);
		delete_last(&stacks->b);
	}
}

void	*ft_free_ptr(void *ptr)
{
	free(ptr);
	return (NULL);
}

void	*ft_free_matrix(char **matrix)
{
	int		i;

	i = 0;
	while (matrix && matrix[i])
	{
		if (matrix[i] != NULL)
			matrix[i] = ft_free_ptr(matrix[i]);
		i++;
	}
	if (matrix != NULL)
		matrix = ft_free_ptr(matrix);
	return (NULL);
}
