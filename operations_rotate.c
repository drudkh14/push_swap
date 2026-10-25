/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbohdanc <zbohdanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 19:42:47 by zbohdanc          #+#    #+#             */
/*   Updated: 2026/08/31 19:49:26 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "operations_helper.h"
#include "libft.h"

int	ra(t_stack *a, int *operations)
{
	if (!a->len)
		return (0);
	rotate(a);
	operations[OP_RA]++;
	ft_putendl_fd("ra", 1);
	return (1);
}

int	rb(t_stack *b, int *operations)
{
	if (!b->len)
		return (0);
	rotate(b);
	operations[OP_RB]++;
	ft_putendl_fd("rb", 1);
	return (1);
}

int	rr(t_stack *a, t_stack *b, int *operations)
{
	if (!a->len || !b->len)
		return (0);
	rotate(a);
	rotate(b);
	operations[OP_RR]++;
	ft_putendl_fd("rr", 1);
	return (1);
}
