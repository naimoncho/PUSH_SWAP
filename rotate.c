/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:20:43 by ncheniou          #+#    #+#             */
/*   Updated: 2025/03/25 13:20:44 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_rotate_node(t_stack **stack)
{
	t_stack	*next;
	t_stack	*last;

	if (!(*stack) || !(*stack)->next)
		return ;
	next = (*stack)->next;
	last = ft_last_node(*stack);
	if (*stack)
	{
		next->prev = NULL;
		last->next = *stack;
		(*stack)->next = NULL;
		(*stack)->prev = last;
		*stack = next;
	}
}

void	ft_rotate(t_stack **stack_a, t_stack **stack_b, int move)
{
	if (move == MOVERA)
	{
		ft_rotate_node(stack_a);
		ft_putstr(RA);
	}
	else if (move == MOVERB)
	{
		ft_rotate_node(stack_b);
		ft_putstr(RB);
	}
	else if (move == MOVERR)
	{
		ft_rotate_node(stack_a);
		ft_rotate_node(stack_b);
		ft_putstr(RR);
	}
}
