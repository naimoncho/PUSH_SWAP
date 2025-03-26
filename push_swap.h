/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:20:59 by ncheniou          #+#    #+#             */
/*   Updated: 2025/03/26 08:52:45 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "./defines.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack	t_stack;

struct					s_stack
{
	int					id;
	long				num;
	int					cost;
	bool				median;
	bool				min_cost;
	t_stack				*target;
	t_stack				*prev;
	t_stack				*next;
};

/* MOVEMENTS */
void					ft_push(t_stack **stack_a, t_stack **stack_b, int move);
void					ft_push_node(t_stack **stack, t_stack **node);
void					ft_swap(t_stack **stack_a, t_stack **stack_b, int move);
void					ft_swap_node(t_stack **stack);
void					ft_rotate(t_stack **stack_a, t_stack **stack_b,
							int move);
void					ft_rotate_node(t_stack **stack);
void					ft_reverse_rotate(t_stack **stack_a, t_stack **stack_b,
							int move);
void					ft_reverse_rotate_node(t_stack **stack);

/* STACK INITIALIZER */
void					ft_stack_duplicate_arg(t_stack *stack);
void					ft_stack_add_node(t_stack **stack, char **nums,
							int *index);
void					ft_stack_init(char *av[], t_stack **stack_a);

/* FIND & PREP SORT */
t_stack					*ft_stack_max(t_stack *stack);
t_stack					*ft_stack_min(t_stack *stack);
int						ft_stack_len(t_stack *stack);
int						ft_stack_sorted(t_stack *stack);
void					ft_stack_above_half(t_stack *stack);

/* SET STACKS*/
t_stack					*ft_stack_set_min_cost(t_stack **stack_a,
							t_stack **stack_b);
void					ft_push_cost(t_stack *stack_a, t_stack *stack_b,
							t_stack *stack_a_node, int *count);
void					ft_stack_set_target_a(t_stack *main_stack, t_stack *b);
t_stack					*ft_stack_set_target_b(t_stack *node, t_stack *stack_a);
void					ft_top_node(t_stack **stack_a, t_stack **stack_b,
							t_stack *min_cost);

/* STACK ORDER AND TURK ALGORITHM */
void					ft_sort_three(t_stack **stack);
void					ft_sort_push_b(t_stack **stack_a, t_stack **stack_b);
void					ft_sort_push_a(t_stack **stack_a, t_stack **stack_b);
void					ft_sort_stack(t_stack **stack_a, t_stack **stack_b);
void					ft_sort_end(t_stack **stack_a, t_stack **stack_b);

/* UTILS PUSHSWAP */
int						ft_syntax(char *s);
void					ft_free_list(t_stack **stack);
t_stack					*ft_last_node(t_stack *lst);
t_stack					*ft_new_node(int id, long num);
void					ft_add_node_back(t_stack **stack, t_stack *new);
long					ft_atol_ps(char *str);

#endif