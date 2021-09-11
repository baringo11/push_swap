/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 19:28:47 by jbaringo          #+#    #+#             */
/*   Updated: 2021/09/10 20:43:15 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	check_instruction(char *line)
{
	if (!ft_strncmp(line, "sa", 3) || !ft_strncmp(line, "sb", 3) \
		|| !ft_strncmp(line, "ss", 3) || !ft_strncmp(line, "pa", 3) \
		|| !ft_strncmp(line, "pb", 3) || !ft_strncmp(line, "ra", 3) \
		|| !ft_strncmp(line, "rb", 3) || !ft_strncmp(line, "rr", 3) \
		|| !ft_strncmp(line, "rra", 4) || !ft_strncmp(line, "rrb", 4) \
		|| !ft_strncmp(line, "rrr", 4))
		return (0);
	return (1);
}

int	read_instructions(t_stacks_checker *stacks)
{
	char	*line;
	char	**instructions;

	instructions = NULL;
	while (get_next_line(0, &line) && line[0] != '\0')
	{
		if (check_instruction(line))
		{
			ft_putstr_fd("Error\n", 2);
			if (instructions)
				instructions = ft_free_matrix(instructions);
			free(line);
			return (1);
		}
		instructions = add_new_pos_matrix(instructions, line);
		free(line);
	}
	if (instructions)
		operations_checker(stacks, instructions);
	free(line);
	instructions = ft_free_matrix(instructions);
	return (0);
}
