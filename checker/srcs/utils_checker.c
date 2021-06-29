#include "../includes/checker.h"

char	**add_new_pos_matrix(char **matrix, char *new)
{
	char	**tmp;
	int		i;

	i = 0;
	while (matrix && matrix[i])
		i++;
	i++;
	tmp = (char **)malloc(sizeof(char *) * (i + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (matrix && matrix[i])
	{
		tmp[i] = ft_strdup(matrix[i]);
		i++;
	}
	tmp[i] = ft_strdup(new);
	tmp[i + 1] = NULL;
	if (matrix)
		matrix = ft_free_matrix(matrix);
	return (tmp);
}

void	clear_stacks_checker(t_stacks_checker *stacks)
{
	if (stacks->a)
	{
		while (stacks->a->next)
			delete_last(&stacks->a);
		delete_last(&stacks->a);
	}
	if (stacks->b)
	{
		while (stacks->b->next)
			delete_last(&stacks->b);
		delete_last(&stacks->b);
	}
}
