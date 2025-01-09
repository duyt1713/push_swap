/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:24:48 by duha              #+#    #+#             */
/*   Updated: 2025/01/09 15:17:55 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static const t_operation op_map[] = {
    {"sa", swap_a},
    {"sb", swap_b},
    {"ss", swap_both},
    {"pa", push_a},
    {"pb", push_b},
    {"ra", rotate_a},
    {"rb", rotate_b},
    {"rr", rotate_both},
    {"rra", reverse_rotate_a},
    {"rrb", reverse_rotate_b},
    {"rrr", reverse_rotate_both},
    {NULL, NULL}  // Sentinel to mark the end of the array
};

void	operations(t_stack *a, t_stack *b, const char *op)
{
	if (!a || !b || !op)
		return ;
	if (ft_strncmp(op, "sa", 2) == 0)
		swap(a);
	else if (ft_strncmp(op, "sb", 2) == 0)
		swap(b);
	else if (ft_strncmp(op, "ss", 2) == 0)
	{
		swap(a);
		swap(b);
	}
	else if (ft_strncmp(op, "pa", 2) == 0)
		push(a, b);
	else if (ft_strncmp(op, "pb", 2) == 0)
		push(b, a);
	else if (ft_strncmp(op, "ra", 2) == 0)
		rotate(a);
	else if (ft_strncmp(op, "rb", 2) == 0)
		rotate(b);
	else if (ft_strncmp(op, "rr", 2) == 0)
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strncmp(op, "rra", 2) == 0)
		r_rotate(a);
	else if (ft_strncmp(op, "rrb", 2) == 0)
		r_rotate(b);
	else if (ft_strncmp(op, "rrr", 2) == 0)
	{
		r_rotate(a);
		r_rotate(b);
	}
	else
		return ;
	ft_putendl_fd(op, 1);
}

static void	swap(t_stack *stack)
{}

static void	push(t_stack *des, t_stack *src)
{}

static void	rotate(t_stack *stack)
{}

static void	r_rotate(t_stack *stack)
{}