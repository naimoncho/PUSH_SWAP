#include "./push_swap.h"

void	ft_swapnode(t_stack **top)
{
	t_stack *first;
	t_stack *second;

	if (!*top || !(*top)->next)
		return ;
	first = *top;
	second = (*top)->next;
	if (first->prev)
		first->prev->next = second;
	if (second->next)
		second->next->prev = first;
	first->next = second->next;
	second->prev = first->prev;
	first->prev = second;
	second->next = first;
	*top = second;
}

void	ft_swap(t_stack **a,t_stack **b, int move)
{
	if (move == MOVESA)
	{
		ft_swapnode(a);
		write(1, "sa\n", 3);
	}

	else if (move == MOVESB)
	{
		ft_swapnode(b);
		write(1, "sb\n", 3);
	}
	if (move == MOVESS)
	{
		ft_swapnode(a);
		ft_swapnode(b);
		write(1, "ss\n", 3);
	}
}