/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 19:28:19 by jbaringo          #+#    #+#             */
/*   Updated: 2021/08/19 19:28:20 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	bigger_than_first(t_stacks *stacks)
{
	if (stacks->b->next->content > stacks->a->content) //mayor que el 1
		operations(stacks, "ra pa pa rra");
	else //menor que el 1
		operations(stacks, "ra pa rra pa");
}

void	bigger_than_second(t_stacks *stacks)
{
	if (stacks->b->next->content > stacks->a->next->content) //mayor que el 2
		operations(stacks, "rra pa pa rra rra");
	else if (stacks->b->next->content > stacks->a->content) //mayor que el 1
		operations(stacks, "rra pa rra pa rra");
	else //menor que el 1
		operations(stacks, "rra pa ra ra pa");
}

void	bigger_than_third(t_stacks *stacks)
{
	if (stacks->b->next->content > stacks->a->next->next->content) //mayor que el 3
		operations(stacks, "pa pa ra ra");
	else if (stacks->b->next->content > stacks->a->next->content) //mayor que el 2
		operations(stacks, "pa rra pa rra rra");
	else if (stacks->b->next->content > stacks->a->content) //mayor que el 1
		operations(stacks, "pa ra ra pa rra");
	else //menor que el 1
		operations(stacks, "pa ra pa");
}

void	sort_5(t_stacks *stacks)
{
	operations(stacks, "pb pb");
	sort_3(stacks);
	if (stacks->b->content < stacks->b->next->content)
		operations(stacks, "sb");
	if (stacks->b->content > stacks->a->next->next->content) //mayor que el 3
		bigger_than_third(stacks);
	else if (stacks->b->content > stacks->a->next->content) //mayor que el 2
		bigger_than_second(stacks);
	else if (stacks->b->content > stacks->a->content) //mayor que el 1
		bigger_than_first(stacks);
	else //menor que el 1
		operations(stacks, "pa pa");
}
