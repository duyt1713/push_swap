/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:00:19 by duha              #+#    #+#             */
/*   Updated: 2025/01/21 02:41:37 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include <stdbool.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				cost;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

t_node		*stack_init(char **args);
void		handle_error(t_node **stack);
bool		args_check_numerical(char **argv);
bool		args_check_dup(char **argv);

#endif
