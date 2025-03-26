/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:20:22 by ncheniou          #+#    #+#             */
/*   Updated: 2025/03/26 08:53:00 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_sort_three(t_stack **stack)
{
	t_stack	*max;

	max = ft_stack_max(*stack);
	if (!ft_stack_sorted(*stack))
	{
		if (*stack == max)
		{
			ft_rotate_node(stack);
			ft_putstr(RA);
		}
		else if ((*stack)->next == max)
		{
			ft_reverse_rotate_node(stack);
			ft_putstr(RRA);
		}
		if ((*stack)->num > (*stack)->next->num)
		{
			ft_swap_node(stack);
			ft_putstr(SA);
		}
	}
}

void	ft_sort_push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min_cost;
	int		len_stack_a;

	len_stack_a = ft_stack_len(*stack_a);
	while (len_stack_a-- > 3 && !ft_stack_sorted(*stack_a))
	{
		ft_stack_above_half(*stack_a);
		ft_stack_above_half(*stack_b);
		min_cost = ft_stack_set_min_cost(stack_a, stack_b);
		ft_top_node(stack_a, stack_b, min_cost);
		ft_push(stack_a, stack_b, MOVEPB);
	}
}

void	ft_sort_push_a(t_stack **stack_a, t_stack **stack_b)
{
	int		len_stack_b;
	t_stack	*target_b;

	len_stack_b = ft_stack_len(*stack_b);
	while (len_stack_b-- > 0)
	{
		ft_stack_above_half(*stack_a);
		ft_stack_above_half(*stack_b);
		target_b = ft_stack_set_target_b(*stack_b, *stack_a);
		while (*stack_a != target_b)
		{
			if (target_b->median)
				ft_rotate(stack_a, stack_b, MOVERA);
			else
				ft_reverse_rotate(stack_a, stack_b, MOVERRA);
		}
		ft_push(stack_a, stack_b, MOVEPA);
	}
}

void	ft_sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	len_stack_a;

	len_stack_a = ft_stack_len(*stack_a);
	if (len_stack_a-- > 3 && !ft_stack_sorted(*stack_a))
		ft_push(stack_a, stack_b, MOVEPB);
	if (len_stack_a-- > 3 && !ft_stack_sorted(*stack_a))
		ft_push(stack_a, stack_b, MOVEPB);
	ft_sort_push_b(stack_a, stack_b);
	ft_sort_three(stack_a);
	ft_sort_push_a(stack_a, stack_b);
	ft_stack_above_half(*stack_a);
	ft_sort_end(stack_a, stack_b);
}

void	ft_sort_end(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min_node;

	min_node = ft_stack_min(*stack_a);
	while (*stack_a != min_node)
	{
		if (min_node->median)
			ft_rotate(stack_a, stack_b, MOVERA);
		else
			ft_reverse_rotate(stack_a, stack_b, MOVERRA);
	}
}
