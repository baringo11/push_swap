/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 19:28:16 by jbaringo          #+#    #+#             */
/*   Updated: 2021/08/19 19:38:06 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_3(t_stacks *stacks)
{
	int	first;
	int	second;
	int	third;

	first = (stacks->a->content > stacks->a->next->content);
	second = (stacks->a->next->content > stacks->a->next->next->content);
	third = (stacks->a->next->next->content > stacks->a->content);
	if (first + second + third == 2)
		operations(stacks, "sa");
	if (check_if_sorted(stacks->a))
		return ;
	first = (stacks->a->content > stacks->a->next->content);
	if (first)
		operations(stacks, "ra");
	else
		operations(stacks, "rra");
}
