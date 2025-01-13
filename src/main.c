/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:02:25 by duha              #+#    #+#             */
/*   Updated: 2025/01/13 16:21:53 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	i;
	char **split;

	if (argc == 1)
		return (1);	//without param

	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		if (!split)
			return (1); //split fail
		i = 0;
		while (split[i])
		{
			ft_printf("Split succeeded.\n");
			free(split[i]);
			i++;
		}
		free(split);
	}
	return (0);
}
