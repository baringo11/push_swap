/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 19:28:42 by jbaringo          #+#    #+#             */
/*   Updated: 2021/08/19 19:28:43 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	main(int argc, char **argv)
{
	t_stacks_checker stacks;

	stacks.a = NULL;
	stacks.b = NULL;
	if (argc < 2 || !check_arguments(&stacks.a, argv))
		return (0);
	if (check_if_sorted(stacks.a) || read_instructions(&stacks))
		return (0);
	if (!check_if_sorted(stacks.a) || stacks.b != NULL)
	{
		ft_putstr_fd("KO\n", 2);
		return (0);
	}
	ft_putstr_fd("OK\n", 2);
	clear_stacks_checker(&stacks);
	return (0);
}
