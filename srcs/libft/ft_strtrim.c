/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 11:47:08 by jbaringo          #+#    #+#             */
/*   Updated: 2021/08/19 20:08:12 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	if (s1 == NULL || set == NULL)
		return (NULL);
	j = ft_strlen(s1);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]) != NULL)
		i++;
	if (i == j)
		return (ft_strdup(""));
	while (s1 && ft_strchr(set, s1[j]) != NULL && j != 0)
		j--;
	j -= i - 1;
	str = malloc((j + 1) * sizeof(char));
	if (!str)
		return (NULL);
	k = 0;
	while (k < j)
		str[k++] = s1[i++];
	str[k] = '\0';
	return (str);
}
