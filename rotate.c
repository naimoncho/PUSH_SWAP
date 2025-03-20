#include "./push_swap.h"

void	ft_rotatenode(t_stack **stacks)
{
	t_stack	*firstnode;
	t_stack *lstnode;

	if (!*stacks || !(*stacks)->next)
		return ;
	firstnode = *stacks;
	lstnode = ft_lstlast_ps(*stacks);
	*stacks = firstnode->next;
	(*stacks)->prev = NULL;
	lstnode->next = firstnode;
	firstnode->next = NULL;
	firstnode->prev = lstnode;
}

void	ft_rotate(t_stack **a,t_stack **b, int move)
{
	if (move == MOVERA)
	{
		ft_rotatenode(a);
		write(1, "ra\n", 3);
	}
	else if (move == MOVERB)
	{
		ft_rotatenode(b);
		write(1, "rb\n", 3);
	}
	if (move == MOVERR)
	{
		ft_rotatenode(a);
		ft_rotatenode(b);
		write(1, "rr\n", 3);
	}
}
