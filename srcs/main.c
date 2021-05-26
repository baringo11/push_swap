#include "../includes/push_swap.h"

// valgrind --leak-check=full \
// 			--show-leak-kinds=all \
// 			--track-origins=yes \
// 			--verbose \
// 			--log-file=valgrind-out.txt \
// 			./push_swap

void	check_if_final_sorted(t_lst *a)
{
	int i = 0;
	while (a->next)
	{
		if (a->content > a->next->content)
		{
			i = 0;
			while (i < 100000 && i++)
				printf("ERROR INCORRECT SORT : n: %d in pos[%d]\n", a->content, i);
			break;
		}
		i++;
		a = a->next;
	}
}

void	print_stacks(t_stacks *stacks)
{
	printf("\n***** STACK B ******\n");
	list_lenght(stacks->b);
	printf("\n***** STACK A ******\n");
	list_lenght(stacks->a);
}

int	main(int argc, char **argv)
{
	t_stacks stacks;

	stacks.a = NULL;
	stacks.b = NULL;
	stacks.cont = 0;
	stacks.nb_to_pushb = 0;
	stacks.moves_ra = 0;
	stacks.moves_rb = 0;
	errno = 0;
	if (argc < 2 || !check_arguments(&stacks.a, argv))
		return (0);
	if (check_if_sorted(stacks.a))
		return (0);
	if (argc == 4)
		sort_3(&stacks);
	else if (argc == 6)
		sort_5(&stacks);
	else
		sort_stack(&stacks, lstsize(stacks.a));
//	printf("\n*************** RESULT ***************\n");
//	list_lenght(stacks.a);
	check_if_final_sorted(stacks.a);
//	printf("cont: %d\n", stacks.cont);
	clear_stacks(&stacks);
}
