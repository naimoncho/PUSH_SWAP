#include "./push_swap.h"

void	ft_pushnode(t_stack **dest, t_stack **src)
{
	t_stack *push;

	if (!*src)
		return ;
	push = *src;
	*src = (*src)->next;
	if (!*dest)
	{
		*dest = push;
		(*dest)->next = NULL;
	}
	else
	{
		push->next = *dest;
		push->next->prev = push;
		if (*src)
			(*src)->prev = NULL;
		*dest = push;
	}
}

void	ft_push(t_stack **a,t_stack **b, int move)
{
	if (move == MOVEPA)
	{
		ft_pushnode(a, b);
		write(1, "pa\n", 3);
	}
	if (move == MOVEPB)
	{
		ft_pushnode(a, b);
		write(1, "pb\n", 3);
	}
}
