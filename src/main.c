/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:02:25 by duha              #+#    #+#             */
/*   Updated: 2025/01/15 23:54:30 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdlib.h>
#include <limits.h>

t_node	**stack_init(char **args);
void	handle_error(t_node **stack);

//argc and argv checks, perform split with single argc
//initialize stack a with stack_init
int	main(int argc, char **argv)
{
	t_node	**stack_a = NULL;
	t_node	**stack_b = NULL;
	char	**split;
	char	**split_original;
	(void)stack_b;

	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (1); // No parameters provided

	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		if (!split)
			return (1); // Split failed

		stack_a = stack_init(split);
		split_original = split;

		while (*split)
			free(*split++);
		free(split_original);
	}
	else
		stack_a = stack_init(argv + 1);

	// perform push_swap
	// free stacks a & b
	free(stack_a);

	return (0);
}

//initialize stack a, handles INT limit check
t_node	**stack_init(char **args)
{
	long	value;
	int		index;
	t_node	**stack;
	t_node	*new_node;
	//t_node	*next_node;
	t_node	*last_node;

	index = 0;
	last_node = NULL;
	stack = (t_node **)malloc(sizeof(t_node *));
	if (!stack)
		return (NULL);

	while (*args)
	{
		value = ft_atol(*args++);
		if (value > INT_MAX || value < INT_MIN) //param greater than MAXINT ot not numerica
			handle_error(stack); //handle free here later as well
		new_node = (t_node *)malloc(sizeof(t_node));
		if (!new_node)
			exit(EXIT_FAILURE);
			//handle_error(a, NULL);
		new_node->value = value;
		new_node->index = ++index;
		new_node->next = NULL;
		if (!*stack)
			*stack = new_node;
		else
			last_node->next = new_node;
		last_node = new_node;
	}
	last_node->next = *stack;
	return (stack);
}

void	handle_error(t_node **stack)
{
	t_node	*current;
	t_node	*next;

	if (stack && *stack)
	{
		current = *stack;
		while (current->next != *stack)
		{
			next = current->next;
			free(current);
			current = next;
		}
		free(current);
		*stack = NULL;
	}
	free(stack);
	ft_printf("Error.\n");
	exit(EXIT_FAILURE);
}