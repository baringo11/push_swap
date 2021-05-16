#include "../includes/push_swap.h"

// valgrind --leak-check=full \
// 			--show-leak-kinds=all \
// 			--track-origins=yes \
// 			--verbose \
// 			--log-file=valgrind-out.txt \
// 			./push_swap

void	print_stacks(t_stacks *stacks)
{
	printf("\n***** STACK B ******\n");
	list_lenght(stacks->b);
	printf("\n***** STACK A ******\n");
	list_lenght(stacks->a);
}

void	operate(t_stacks *stacks)
{
	print_stacks(stacks);

	operations(stacks, "sa");
	operations(stacks, "pb");

	print_stacks(stacks);

	operations(stacks, "pb");
	operations(stacks, "pb");
	operations(stacks, "sa");
	operations(stacks, "pa");
	operations(stacks, "pa");
	operations(stacks, "pa");

	print_stacks(stacks);
}

int	main(int argc, char **argv)
{
	t_stacks stacks;

	stacks.a = NULL;
	stacks.b = NULL;
	if (argc < 2 || !check_arguments(&stacks.a, argv))
		return (0);

	operate(&stacks);
	clear_stacks(&stacks);
}