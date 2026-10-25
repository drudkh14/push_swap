/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_five_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbohdanc <zbohdanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 15:12:27 by zbohdanc          #+#    #+#             */
/*   Updated: 2026/09/01 15:12:40 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_four_five_b.h"
#include "stack.h"
#include "sort_three_b.h"
#include "operations.h"
#include "sorting_helper.h"

int	sort_four_five_b(t_stack *a, t_stack *b, size_t n, int *operations)
{
	int		res;
	size_t	i;

	res = 0;
	i = n;
	while (i > 3)
	{
		if (i == b->len)
			res += ext_to_a(a, b, find_index_maximum(b, b->len), operations);
		else
			res += ext_to_a_reset(a, b, find_index_maximum(b, i), operations);
		i--;
	}
	res += sort_three_b(a, b, operations);
	return (res);
}
