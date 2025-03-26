/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:21:06 by ncheniou          #+#    #+#             */
/*   Updated: 2025/03/26 08:53:21 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	main(int ac, char *av[])
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	stack_a = ft_calloc(1, sizeof(t_stack *));
	stack_b = ft_calloc(1, sizeof(t_stack *));
	if (ac > 1)
	{
		ft_stack_init(av, stack_a);
		if (!ft_stack_sorted(*stack_a))
		{
			if (ft_stack_len(*stack_a) == 2)
				ft_swap(stack_a, stack_b, MOVESA);
			else if (ft_stack_len(*stack_a) == 3)
				ft_sort_three(stack_a);
			else
				ft_sort_stack(stack_a, stack_b);
		}
		ft_free_list(stack_a);
		ft_free_list(stack_b);
	}
	else
		ft_putstr_fd("Error\n", STDERR_FILENO);
}
