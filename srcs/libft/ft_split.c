/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:12:49 by jbaringo          #+#    #+#             */
/*   Updated: 2021/08/19 20:02:54 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char str, char c)
{
	if (str == c)
		return (0);
	else
		return (1);
}

int	count_words(const char *str, char c)
{
	int		count;

	count = 0;
	while (*str)
	{
		while (*str && ft_isspace(*str, c) == 0)
			str++;
		if (*str && ft_isspace(*str, c) == 1)
		{
			count++;
			while (*str && ft_isspace(*str, c) == 1)
				str++;
		}
	}
	return (count);
}

char	*malloc_word(const char *str, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && ft_isspace(str[i], c) == 1)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] && ft_isspace(str[i], c) == 1)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	*free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	int		i;

	if (s == NULL)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && ft_isspace(*s, c) == 0)
			s++;
		if (*s && ft_isspace(*s, c) == 1)
		{
			arr[i] = malloc_word(s, c);
			if (!arr[i])
				return (free_arr(arr));
			i++;
			while (*s && ft_isspace(*s, c) == 1)
				s++;
		}
	}
	arr[i] = NULL;
	return (arr);
}
