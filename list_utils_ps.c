#include "push_swap.h"

int	ft_lstsize_ps(t_stack *lst)
{
	int	counter;
	t_stack *auxiliar;

	counter = 0;
	auxiliar = lst;
	if (!lst)
		return (0);
	while (auxiliar != NULL)
	{
		counter ++;
		auxiliar = auxiliar->next;
	}
	return (counter);
}

t_stack	*ft_lstlast_ps(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_lstlen_ps(t_stack *stacks)
{
	int i;

	i = 0;
	if (!stacks)
		return (0);
	while (stacks)
	{
		stacks = stacks->next;
		i ++;
	}
	return (i);
}

void	ft_lstadd_back_ps(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (NULL == lst)
		return ;
	if (NULL == *lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast_ps(*lst);
	last->next = new;
}

t_stack	*ft_lstnew_ps(int index, long num)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->index	 = index;
	node->dataarg = num;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}