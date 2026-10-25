/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rrotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbohdanc <zbohdanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 19:43:47 by zbohdanc          #+#    #+#             */
/*   Updated: 2026/08/31 19:49:38 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "operations_helper.h"
#include "libft.h"

int	rra(t_stack *a, int *operations)
{
	if (!a->len)
		return (0);
	reverse_rotate(a);
	operations[OP_RRA]++;
	ft_putendl_fd("rra", 1);
	return (1);
}

int	rrb(t_stack *b, int *operations)
{
	if (!b->len)
		return (0);
	reverse_rotate(b);
	operations[OP_RRB]++;
	ft_putendl_fd("rrb", 1);
	return (1);
}

int	rrr(t_stack *a, t_stack *b, int *operations)
{
	if (!a->len || !b->len)
		return (0);
	reverse_rotate(a);
	reverse_rotate(b);
	operations[OP_RRR]++;
	ft_putendl_fd("rrr", 1);
	return (1);
}
