/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kateslia <kateslia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 19:41:45 by kateslia          #+#    #+#             */
/*   Updated: 2026/09/02 17:42:47 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "insertion_sort.h"
#include "sorting_helper.h"
#include "stack.h"
#include "operations.h"
#include "small_sorting.h"

int	insertion_sort(t_stack *a, t_stack *b, int *operations)
{
	int	res;

	res = 0;
	while (a->len > 5)
		res += ext_to_b(a, b, find_index_minimum(a, a->len), operations);
	res += sort_small(a, b, a->len, operations);
	while (b->len)
		res += pa(a, b, operations);
	return (res);
}
