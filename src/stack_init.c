/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:46:52 by duha              #+#    #+#             */
/*   Updated: 2025/01/21 02:40:49 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdlib.h>
#include <limits.h>

static void	push(t_node **stack, t_node **last_node, long value, int index);

//initialize stack a, handles INT limit check
t_node	*stack_init(char **args)
{
	long	value;
	int		index;
	t_node	*stack;
	t_node	*last_node;

	index = 0;
	stack = NULL;
	last_node = NULL;
	while (*args)
	{
		value = ft_atol(*args++);
		if (value > INT_MAX || value < INT_MIN)
			handle_error(&stack); // Handle free here later as well
		push(&stack, &last_node, value, ++index);
	}
	return (stack);
}

static void	push(t_node **stack, t_node **last_node, long value, int index)
{
	t_node	*new_node;

	new_node = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!new_node)
		exit(EXIT_FAILURE);
	new_node->value = (int)value;
	new_node->index = index;
	if (!*stack)
		*stack = new_node;
	else
	{
		new_node->next = *stack;
		new_node->prev = *last_node;
		(*last_node)->next = new_node;
		(*stack)->prev = new_node;
	}
	*last_node = new_node;
}
