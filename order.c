#include "push_swap.h"

void	ft_stack_median(t_stack *stacks)
{
	int	half;
	int	med;
	int	i;

	i = 1;
	half = ft_lstlen_ps(stacks);
	med = half / 2;
	if (half % 2)
		med ++;
	while (stacks)
	{
		stacks->index = i ++;
		if (stacks->index <= med)
			stacks->median = true;
		else
			stacks->median = false;
	}	
}

bool	ft_stackorder(t_stack *stacks)
{
	if (!stacks)
		return (true);
	while (stacks && stacks->next)
	{
		if (stacks->dataarg > stacks->next->dataarg)
			return (false);
		stacks = stacks->next;
	}
	return (true);
}

void	ft_sort_three(t_stack **a)
{
	t_stack	*max;

	max = ft_findmax(*a);
	if (!ft_stackorder(*a))
	{
		if (*a == max)
		{
			ft_rotatenode(a);
			write(1, "ra\n", 3);
		}
		else if ((*a)->next == max)
		{
			ft_rever_rotatenode(a);
			write(1, "rra\n", 4);
		}
		if ((*a)->dataarg > (*a)->next->dataarg)
		{
			ft_swapnode(a);
			write(1, "sa\n", 3);
		}
	}
}

void	ft_sort_pb(t_stack **a, t_stack **b)
{
	t_stack	*cost;
	int		len;

	len = ft_lstlen_ps(*a);
	while (len-- > 3 && !ft_stackorder(*a))
	{
		ft_stack_median(*a);
		ft_stack_median(*b);
		cost = ft_cheapest(a, b);
		if (!cost || !cost->target)
			return;
		ft_stack_top_head(a, b, cost);
		ft_push(a, b, MOVEPB);
	}
}

void	ft_sort_pa(t_stack **a, t_stack **b)
{
	t_stack	*node_b;
	int		len;

	len = ft_lstlen_ps(*b);
	while (len-- > 0)
	{
		ft_stack_median(*a);
		ft_stack_median(*b);
		node_b = ft_set_b(*a, *b);
		if (!node_b)
			break ;
		while (*a != node_b)
		{
			if (node_b->median)
			{
				ft_rotatenode(a);
				write(1, "ra\n", 3);
			}
			else
			{
				ft_rever_rotatenode(a);
				write(1, "rra\n", 4);
			}
		}
		ft_push(a, b, MOVEPA);
	}
}