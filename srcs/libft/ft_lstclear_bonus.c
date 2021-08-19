/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 13:25:00 by jbaringo          #+#    #+#             */
/*   Updated: 2021/08/19 20:04:18 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*begin;

	begin = *lst;
	if (lst)
	{
		while (*lst)
		{
			begin = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = begin;
		}
	}
}
