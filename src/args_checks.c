/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 02:41:56 by duha              #+#    #+#             */
/*   Updated: 2025/01/26 07:14:28 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	char	**current;
	char	**compare;

	current = argv;
	while (*current)
	{
		compare = current + 1;
		while (*compare)
		{
			if (ft_strcmp(*current, *compare) == 0)
				return (false);
			compare++;
		}
		current++;
	}
	return (true);
}
