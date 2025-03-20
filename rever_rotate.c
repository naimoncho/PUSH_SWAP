#include "./push_swap.h"

void	ft_rever_rotatenode(t_stack **stacks)
{
	t_stack *lstnode;
	t_stack *secondlast;

	if (!*stacks || !(*stacks)->next)
		return ;
	lstnode = ft_lstlast_ps(*stacks);
	secondlast = lstnode->prev;
	secondlast->next = NULL;
	lstnode->prev = NULL;
	lstnode->next = *stacks;
	(*stacks)->prev = lstnode;
	*stacks = lstnode;
}

void	ft_rever_rotate(t_stack **a,t_stack **b, int move)
{
	if (move == MOVERRA)
	{
		ft_rever_rotatenode(a);
		write(1, "rra\n", 4);
	}
	else if (move == MOVERRB)
	{
		ft_rever_rotatenode(b);
		write(1, "rrb\n", 4);
	}
	else if (move == MOVERRR)
	{
		ft_rever_rotatenode(a);
		ft_rever_rotatenode(b);
		write(1, "rrr\n", 4);
	}
}
