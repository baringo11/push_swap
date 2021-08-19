/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 19:27:58 by jbaringo          #+#    #+#             */
/*   Updated: 2021/08/19 19:33:23 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	error_mesagge(int n)
{
	if (n == 1)
		ft_putstr_fd("error, not digit argument\n", 2);
	else if (n == 2)
		ft_putstr_fd("error, max int\n", 2);
	else if (n == 3)
		ft_putstr_fd("error, repeated number\n", 2);
	return (0);
}

int	check_repeat_numbers(t_lst **stack_a)
{
	t_lst	*tmp;
	t_lst	*a;

	a = *stack_a;
	while (a->next)
	{
		tmp = a;
		tmp = tmp->next;
		while (tmp->next)
		{
			if (a->content == tmp->content)
				return (error_mesagge(3));
			tmp = tmp->next;
		}
		if (a->content == tmp->content)
			return (error_mesagge(3));
		a = a->next;
	}
	return (1);
}

int	check_max_int(char *s, int nb)
{
	int	i;
	int	negative;

	negative = s[0] == '-';
	i = negative;
	while (s[i])
	{
		if (nb == 0 && s[i] != '0')
			return (1);
		else if (nb == -1 && !negative)
			return (1);
		i++;
	}
	return (0);
}

int	check_numbers(t_lst **stack_a, char **arguments)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	while (arguments[i])
	{
		j = arguments[i][0] == '-' || arguments[i][0] == '+';
		while (arguments[i][j])
		{
			if (!ft_isdigit(arguments[i][j]) && arguments[i][j] != ' ')
				return (error_mesagge(1));
			j++;
		}
		nb = ft_atoi(arguments[i]);
		if ((nb == -1 || nb == 0) && check_max_int(arguments[i], nb))
			return (error_mesagge(2));
		lstadd_back(stack_a, lstnew(nb));
		i++;
	}
	return (1);
}

int	check_arguments(t_lst **stack_a, char **argv)
{
	int		i;
	char	**arguments;

	i = 1;
	while (argv[i])
	{
		arguments = ft_split(argv[i], ' ');
		if (!check_numbers(stack_a, arguments))
			return (0);
		ft_free_matrix(arguments);
		i++;
	}
	if (!check_repeat_numbers(stack_a))
		return (0);
	return (1);
}
