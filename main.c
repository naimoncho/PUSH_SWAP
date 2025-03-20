#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	**a;
	t_stack	**b;

	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		ft_stack_in(argv, a);
		if (!ft_stackorder(*a))
		{
			if (ft_lstlen_ps(*a) == 2)
				ft_swap(a, b, MOVESA);
			else if (ft_lstlen_ps(*a) == 3)
				ft_sort_three(a);
			else
				ft_sort_stacks(a, b);
		}
		ft_free_stacks(a);
		ft_free_stacks(b);
	}
	else
		write (2, "Error\n", 6);
}
