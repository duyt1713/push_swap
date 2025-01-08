/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:24:48 by duha              #+#    #+#             */
/*   Updated: 2025/01/08 17:31:51 by duha             ###   ########.fr       */
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
	if (ft_strcmp(op, "sa") == 0)
		swap(a);
	else if (ft_strcmp(op, "sb") == 0)
		swap(b);
	else if (ft_strcmp(op, "ss") == 0)
	{
		swap(a);
		swap(b);
	}
	else if (ft_strcmp(op, "pa") == 0)
		push(a, b);
	else if (ft_strcmp(op, "pb") == 0)
		push(b, a);
	else if (ft_strcmp(op, "ra") == 0)
		rotate(a);
	else if (ft_strcmp(op, "rb") == 0)
		rotate(b);
	else if (ft_strcmp(op, "rr") == 0)
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strcmp(op, "rra") == 0)
		r_rotate(a);
	else if (ft_strcmp(op, "rrb") == 0)
		r_rotate(b);
	else if (ft_strcmp(op, "rrr") == 0)
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