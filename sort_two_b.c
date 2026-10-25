/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbohdanc <zbohdanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 15:10:51 by zbohdanc          #+#    #+#             */
/*   Updated: 2026/09/01 15:11:06 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_two_b.h"
#include "operations.h"

int	sort_two_b(t_stack *a, t_stack *b, int *operations)
{
	int	res;

	res = 0;
	if (b->head->value < b->head->next->value)
		res += sb(b, operations);
	res += pa(a, b, operations);
	res += pa(a, b, operations);
	return (res);
}
