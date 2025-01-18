/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:02:25 by duha              #+#    #+#             */
/*   Updated: 2025/01/18 22:04:27 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdlib.h>
#include <limits.h>

t_node	*stack_init(char **args);
void	handle_error(t_node *stack);
bool	args_check_numerical(char **argv);
bool	args_check_dup(char **argv);

//argc and argv checks, perform split with single argc
//initialize stack a with stack_init
int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**split;
	char	**split_original;
	(void)stack_b;

	stack_a = NULL;
	stack_b = NULL;
	split = NULL;
	split_original = NULL;

	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (1); // No parameters provided

	// has to be after split
	if (!args_check_numerical(argv) || !args_check_dup(argv))
	{
		ft_printf("Error.\n");
		return (1);
	}

	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		if (!split)
			return (1); // Split failed

		// insert checks here

		stack_a = stack_init(split);
		split_original = split;
		while (*split)
			free(*split++);
		free(split_original);
	}
	else
		// insert checks here
		stack_a = stack_init(argv + 1);

	if (!stack_a)
		handle_error(stack_a);

	// perform push_swap
	// free stacks a & b

	return (0);
}

bool	args_check_numerical(char **argv)
{
	char	*arg;

	while (*argv)
	{
		arg = *argv;
		if (*arg == '-' || *arg == '+')
			arg++;
		if (!*arg)
			return (false);
		while (*arg)
		{
			if (!ft_isdigit(*arg))
				return (false);
			arg++;
		}
		argv++;
	}
	return (true);
}

bool	args_check_dup(char **argv)
{
	char	*current;
	char	*compare;

	while (*argv)
	{
		current = *argv;
		compare = current + 1;
		while (*compare)
		{
			if (ft_strncmp(current, compare, ft_strlen(current)) == 0)
				return (false);
			compare++;
		}
		current++;
	}
	return (true);
}


//initialize stack a, handles INT limit check
t_node	*stack_init(char **args)
{
	long	value;
	int		index;
	t_node	*stack;
	t_node	*current_node;
	t_node	*prev_node;

	index = 0;
	stack = NULL;
	prev_node = NULL;
	while (*args)
	{
		//dup check
		value = ft_atol(*args++);
		if (value > INT_MAX || value < INT_MIN) //param greater than MAXINT ot not numerica
			handle_error(stack); //handle free here later as well
		current_node = ft_calloc(1, sizeof(t_node));
		if (!current_node)
			exit(EXIT_FAILURE);
			//handle_error(a, NULL);
		current_node->value = value;
		current_node->index = ++index;
		if (!stack)
			stack = current_node;
		else
		{
			prev_node->next = current_node;
			current_node->prev = prev_node;
		}
		prev_node = current_node;
		ft_printf("Node value: %i\nNode index: %i\n", current_node->value, current_node->index);
	}
	prev_node->next = stack;
	(stack)->prev = current_node;
	return (stack);
}

void	handle_error(t_node *stack)
{
	t_node	*current;
	t_node	*next;

	if (stack)
	{
		current = stack;
		while (current->next != stack)
		{
			next = current->next;
			free(current);
			current = next;
		}
		free(current);
		stack = NULL;
	}
	free(stack);
	ft_printf("Error.\n");
	exit(EXIT_FAILURE);
}