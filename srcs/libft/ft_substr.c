/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 10:36:50 by jbaringo          #+#    #+#             */
/*   Updated: 2021/08/19 20:11:30 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*n;
	size_t	i;

	n = malloc(sizeof(char) * (len + 1));
	if (!n || !s)
		return (NULL);
	i = 0;
	if (start < ft_strlen(s))
	{
		while (s && i < len)
		{
			n[i] = s[start];
			start++;
			i++;
		}
	}
	n[i] = '\0';
	return (n);
}
