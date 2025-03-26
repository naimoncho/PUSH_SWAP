/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:20:38 by ncheniou          #+#    #+#             */
/*   Updated: 2025/03/25 16:41:02 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_stack_duplicates(t_stack *stack)
{
	t_stack	*next_num;

	while (stack)
	{
		next_num = stack->next;
		while (next_num != NULL)
		{
			if (stack->num == next_num->num)
			{
				ft_putstr_fd("Error\n", STDERR_FILENO);
				exit(EXIT_FAILURE);
			}
			next_num = next_num->next;
		}
		stack = stack->next;
	}
}

void	ft_stack_add_node(t_stack **stack, char **nums, int *index)
{
	int		j;
	long	num;
	t_stack	*node;

	num = 0;
	if (!nums[1])
	{
		num = ft_atol_ps(nums[0]);
		if (num == (long)INT_MAX + 1)
			(ft_putstr_fd("Error\n", STDERR_FILENO));
		node = ft_new_node((*index)++, num);
		ft_add_node_back(stack, node);
	}
	else
	{
		j = 0;
		while (nums[j])
		{
			num = ft_atol_ps(nums[j++]);
			if (num == (long)INT_MAX + 1)
				(ft_putstr_fd("Error\n", STDERR_FILENO));
			node = ft_new_node((*index)++, num);
			ft_add_node_back(stack, node);
		}
	}
}

void	ft_stack_init(char *av[], t_stack **stack_a)
{
	int		i;
	int		index;
	char	**numbers;

	i = 0;
	index = 1;
	while (av[++i])
	{
		if (av[i][0] != '\0')
		{
			numbers = ft_split(av[i], ' ');
			ft_stack_add_node(stack_a, numbers, &index);
			ft_stack_duplicates(*stack_a);
			ft_free_all(numbers);
		}
		else
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
	}
}
