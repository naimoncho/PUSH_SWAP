/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:20:00 by ncheniou          #+#    #+#             */
/*   Updated: 2025/03/25 13:20:05 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_swap_node(t_stack **stack)
{
	t_stack	*aux;
	int		num;

	aux = *stack;
	if (*stack)
	{
		num = aux->next->num;
		aux->next->num = aux->num;
		aux->num = num;
	}
}

void	ft_swap(t_stack **stack_a, t_stack **stack_b, int move)
{
	if (move == MOVESA)
	{
		ft_swap_node(stack_a);
		ft_putstr(SA);
	}
	else if (move == MOVESB)
	{
		ft_swap_node(stack_b);
		ft_putstr(SB);
	}
	else if (move == MOVESS)
	{
		ft_swap_node(stack_a);
		ft_swap_node(stack_b);
		ft_putstr(SS);
	}
}
