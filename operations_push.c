/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbohdanc <zbohdanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 19:39:33 by zbohdanc          #+#    #+#             */
/*   Updated: 2026/08/31 19:47:55 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "operations_helper.h"
#include "libft.h"

int	pa(t_stack *a, t_stack *b, int *operations)
{
	if (!b->len)
		return (0);
	push(b, a);
	operations[OP_PA]++;
	ft_putendl_fd("pa", 1);
	return (1);
}

int	pb(t_stack *a, t_stack *b, int *operations)
{
	if (!a->len)
		return (0);
	push(a, b);
	operations[OP_PB]++;
	ft_putendl_fd("pb", 1);
	return (1);
}
