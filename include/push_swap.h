/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:00:19 by duha              #+#    #+#             */
/*   Updated: 2025/01/08 17:18:46 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				num;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct s_operation
{
	const char	*op_name;
	void		(*func)(t_stack*, t_stack*);
}				t_operation;

#endif