/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:20:47 by ncheniou          #+#    #+#             */
/*   Updated: 2025/03/25 13:20:48 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_reverse_rotate_node(t_stack **stack)
{
	t_stack	*last;
	t_stack	*prev_last;

	if (!(*stack) || !(*stack)->next)
		return ;
	prev_last = ft_last_node(*stack)->prev;
	last = ft_last_node(*stack);
	if (*stack)
	{
		last->prev = NULL;
		last->next = *stack;
		last->next->prev = last;
		prev_last->next = NULL;
		*stack = last;
	}
}

void	ft_reverse_rotate(t_stack **stack_a, t_stack **stack_b, int move)
{
	if (move == MOVERRA)
	{
		ft_reverse_rotate_node(stack_a);
		ft_putstr(RRA);
	}
	else if (move == MOVERRB)
	{
		ft_reverse_rotate_node(stack_b);
		ft_putstr(RRB);
	}
	else if (move == MOVERRR)
	{
		ft_reverse_rotate_node(stack_a);
		ft_reverse_rotate_node(stack_b);
		ft_putstr(RRR);
	}
}
