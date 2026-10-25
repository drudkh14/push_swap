/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kateslia <kateslia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 17:26:57 by kateslia          #+#    #+#             */
/*   Updated: 2026/09/02 15:32:51 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <stdlib.h>

typedef struct s_part_res
{
	size_t	rotated;
	size_t	pushed;
	size_t	pushed_rotated;
	int		flag;
}			t_part_res;

typedef enum e_straregy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}	t_strategy;

typedef enum e_operation
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OPERATION_COUNT
}	t_operation;

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node		*head;
	t_node		*tail;
	size_t		len;
}				t_stack;

typedef struct s_flags
{
	t_strategy	strategy;
	int			benchmark;
}				t_flags;

#endif
