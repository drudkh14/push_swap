/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbohdanc <zbohdanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 19:25:55 by zbohdanc          #+#    #+#             */
/*   Updated: 2026/08/31 19:30:19 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations_helper.h"
#include "stack.h"

void	reverse_rotate(t_stack *stack)
{
	add_front(stack, pop_back(stack));
}

void	rotate(t_stack *stack)
{
	add_back(stack, pop_front(stack));
}

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->len <= 1)
		return ;
	tmp = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = tmp;
}

void	push(t_stack *src, t_stack *dest)
{
	if (!src->len)
		return ;
	add_front(dest, pop_front(src));
}
