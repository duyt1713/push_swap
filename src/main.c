/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:02:25 by duha              #+#    #+#             */
/*   Updated: 2025/01/14 18:08:03 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdlib.h>
#include <limits.h>

void	stack_init(t_node **a, char **argv);

//argc and argv checks, perform split with single argc
//initialize stack a with stack_init
int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	(void)b;
	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (1);

	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			return (1); //split fail, verify this check
		stack_init(&a, argv);
	}
	stack_init(&a, argv + 1);
	return (0);
}

//initialize stack a, handles INT limit check
void	stack_init(t_node **a, char **argv)
{
	long	value;
	int		index;
	t_node	*new_node;
	t_node	*first_node;
	t_node	*last_node;

	first_node = NULL;
	last_node = NULL;
	index = 0;
	while (*argv && ++index)
	{
		value = ft_atol(*argv++);
		if (value > INT_MAX || value < INT_MIN)
			exit(EXIT_FAILURE);
		new_node = (t_node *)malloc(sizeof(t_node));
		if (!new_node)
			exit(EXIT_FAILURE);
		new_node->value = value;
		new_node->index = index;
		new_node->next = *a;
		*a = new_node;
		if (!first_node)
			first_node = new_node;
		last_node = new_node;
	}
	last_node->next = first_node;
}
