/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:00:19 by duha              #+#    #+#             */
/*   Updated: 2025/01/18 17:36:57 by duha             ###   ########.fr       */
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

#endif