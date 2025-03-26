/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:20:14 by ncheniou          #+#    #+#             */
/*   Updated: 2025/03/25 16:42:08 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_free_list(t_stack **stack)
{
	t_stack	*aux;

	while (*stack)
	{
		aux = (*stack)->next;
		free(*stack);
		*stack = aux;
	}
	free(stack);
}

t_stack	*ft_last_node(t_stack *lst)
{
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_stack	*ft_new_node(int id, long num)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->id = id;
	stack->num = num;
	stack->prev = NULL;
	stack->next = NULL;
	return (stack);
}

void	ft_add_node_back(t_stack **stack, t_stack *new)
{
	t_stack	*aux;

	aux = ft_last_node(*stack);
	if (*stack != NULL)
	{
		new->prev = aux;
		new->next = NULL;
		aux->next = new;
	}
	else
		*stack = new;
}

long	ft_atol_ps(char *str)
{
	long	n;
	int		i;
	long	sign;

	n = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	if (!ft_isdigit(str[i]))
		(ft_putstr_fd("Error\n", STDERR_FILENO), exit(EXIT_FAILURE));
	while (ft_isdigit(str[i]))
		n = (str[i++] - '0') + (n * 10);
	if (!ft_isdigit(str[i]) && str[i])
		(ft_putstr_fd("Error\n", STDERR_FILENO), exit(EXIT_FAILURE));
	n *= sign;
	if (n > INT_MAX || n < INT_MIN)
		(ft_putstr_fd("Error\n", STDERR_FILENO), exit(EXIT_FAILURE));
	return (n);
}
