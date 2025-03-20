/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:46:29 by ncheniou          #+#    #+#             */
/*   Updated: 2025/03/20 08:51:53 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_all(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

void	ft_errors_free(t_stack **a)
{
	ft_free_stacks(a);
	write(2, "Error\n", 6);
	exit(0);
}

void	ft_free_stacks(t_stack **stacks)
{
	t_stack	*current;

	
	while (*stacks)
	{
		current = (*stacks)->next;
		free(*stacks);
		*stacks = current;
	}
	free(stacks);
}

void	ft_duplicates(t_stack *s)
{
	t_stack *num;

	while (s)
	{
		num = s->next;
		while (num != NULL)
		{
			if (s->dataarg == num->dataarg)
			{
				write(2, "Error\n", 6);
				break ;
			}
			num =  num->next;
		}
		s = s->next;
	}	
}
