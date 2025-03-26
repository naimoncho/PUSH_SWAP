/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:20:52 by ncheniou          #+#    #+#             */
/*   Updated: 2025/03/25 13:20:53 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_push_node(t_stack **stack, t_stack **node)
{
	t_stack	*aux;

	if (!stack || !(*node))
		return ;
	aux = *node;
	*node = (*node)->next;
	if (!(*stack))
	{
		*stack = aux;
		(*stack)->next = NULL;
	}
	else
	{
		aux->next = *stack;
		aux->prev = NULL;
		if (*node)
			(*node)->prev = NULL;
		(*stack)->prev = aux;
		*stack = aux;
	}
}

void	ft_push(t_stack **stack_a, t_stack **stack_b, int move)
{
	if (move == MOVEPA)
	{
		ft_push_node(stack_a, stack_b);
		ft_putstr(PA);
	}
	else if (move == MOVEPB)
	{
		ft_push_node(stack_b, stack_a);
		ft_putstr(PB);
	}
}
