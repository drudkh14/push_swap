/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbohdanc <zbohdanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 19:41:39 by zbohdanc          #+#    #+#             */
/*   Updated: 2026/08/31 19:49:01 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "operations_helper.h"
#include "libft.h"

int	sa(t_stack *a, int *operations)
{
	if (!a->len)
		return (0);
	swap(a);
	operations[OP_SA]++;
	ft_putendl_fd("sa", 1);
	return (1);
}

int	sb(t_stack *b, int *operations)
{
	if (!b->len)
		return (0);
	swap(b);
	operations[OP_SB]++;
	ft_putendl_fd("sb", 1);
	return (1);
}

int	ss(t_stack *a, t_stack *b, int *operations)
{
	if (!a->len || !b->len)
		return (0);
	swap(a);
	swap(b);
	operations[OP_SS]++;
	ft_putendl_fd("ss", 1);
	return (1);
}
