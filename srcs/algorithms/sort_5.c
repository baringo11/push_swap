/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 19:28:19 by jbaringo          #+#    #+#             */
/*   Updated: 2021/09/10 19:56:32 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	bigger_than_first(t_stacks *stacks)
{
	if (stacks->b->next->content > stacks->a->content)
		operations(stacks, "ra pa pa rra", -1);
	else
		operations(stacks, "ra pa rra pa", -1);
}

void	bigger_than_second(t_stacks *stacks)
{
	if (stacks->b->next->content > stacks->a->next->content)
		operations(stacks, "rra pa pa rra rra", -1);
	else if (stacks->b->next->content > stacks->a->content)
		operations(stacks, "rra pa rra pa rra", -1);
	else
		operations(stacks, "rra pa ra ra pa", -1);
}

void	bigger_than_third(t_stacks *stacks)
{
	if (stacks->b->next->content > stacks->a->next->next->content)
		operations(stacks, "pa pa ra ra", -1);
	else if (stacks->b->next->content > stacks->a->next->content)
		operations(stacks, "pa rra pa rra rra", -1);
	else if (stacks->b->next->content > stacks->a->content)
		operations(stacks, "pa ra ra pa rra", -1);
	else
		operations(stacks, "pa ra pa", -1);
}

void	sort_5(t_stacks *stacks)
{
	operations(stacks, "pb pb", -1);
	sort_3(stacks);
	if (stacks->b->content < stacks->b->next->content)
		operations(stacks, "sb", -1);
	if (stacks->b->content > stacks->a->next->next->content)
		bigger_than_third(stacks);
	else if (stacks->b->content > stacks->a->next->content)
		bigger_than_second(stacks);
	else if (stacks->b->content > stacks->a->content)
		bigger_than_first(stacks);
	else
		operations(stacks, "pa pa", -1);
}
