/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:02:25 by duha              #+#    #+#             */
/*   Updated: 2025/01/26 16:07:34 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdlib.h>

void	handle_error(t_node **stack);
void	free_split(char **split);

//argc and argv checks, perform split with single argc
//initialize stack a with stack_init
int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**split_argv;
	(void)stack_b;

	stack_a = NULL;
	stack_b = NULL;
	split_argv = NULL;

//remake args_check_init
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (1); // No parameters provided

	if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		split_argv = ft_split(argv[1], ' ');
		if (!split_argv)
			return (1); // Split failed
		argv = split_argv;
	}
	else
		argv++;
	if (!args_check_numerical(argv) || !args_check_dup(argv))
	{
		write(2, "Error\n", 6);
		if (split_argv)
			free_split(split_argv);
		return (1);
	}
	stack_a = stack_init(argv);
	if (split_argv)
		free_split(split_argv);
	if (!stack_a)
		handle_error(&stack_a);

	// perform push_swap
	// free stacks a & b

	return (0);
}

void	free_split(char **split)
{
	char	**temp;

	temp = split;
	while (*temp)
		free(*temp++);
	free(split);
}
//check this later
void	handle_error(t_node **stack)
{
	t_node	*current;
	t_node	*next;

	if (stack)
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
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
