#include "../includes/push_swap.h"

void	clear_lst(t_lst *stack)
{
	if (stack)
	{
		while (stack->next)
			delete_last(&stack);
		delete_last(&stack);
	}
}

void	clear_stacks(t_stacks *stacks)
{
	clear_lst(stacks->a);
	clear_lst(stacks->b);
	//free(stacks);
}

void	*ft_free_ptr(void *ptr)
{
	free(ptr);
	return (NULL);
}

void	*ft_free_matrix(char **matrix)
{
	int		i;

	i = 0;
	while (matrix[i])
	{
		if (matrix[i] != NULL)
			matrix[i] = ft_free_ptr(matrix[i]);
		i++;
	}
	if (matrix != NULL)
		matrix = ft_free_ptr(matrix);
	return (NULL);
}