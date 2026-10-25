/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbohdanc <zbohdanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:49:22 by zbohdanc          #+#    #+#             */
/*   Updated: 2026/09/01 14:58:09 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunk_sort.h"
#include "index_stack.h"
#include "operations.h"
#include "stack.h"
#include "small_sorting.h"
#include "sorting_helper.h"

static int	partition_chunk_sort(t_stack *a, t_stack *b, int chunk_s, int *ops);
static int	ft_sqrt(int n);

int	chunk_sort(t_stack *a, t_stack *b, int *operations)
{
	int		chunk_size;
	int		res;

	if (a->len <= 5)
		return (sort_small(a, b, a->len, operations));
	res = 0;
	index_stack(a);
	chunk_size = ft_sqrt(a->len);
	res += partition_chunk_sort(a, b, chunk_size, operations);
	while (b->len)
		res += ext_to_a(a, b, find_index_maximum(b, b->len), operations);
	return (res);
}

static int	partition_chunk_sort(t_stack *a, t_stack *b, int chunk_s, int *ops)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (a->len)
	{
		if (a->head->value <= i)
		{
			res += pb(a, b, ops) + rb(b, ops);
			i++;
		}
		else if (a->head->value < i + chunk_s)
		{
			res += pb(a, b, ops);
			i++;
		}
		else
			res += ra(a, ops);
	}
	return (res);
}

static int	ft_sqrt(int n)
{
	int	res;

	res = 1;
	while (res * res <= n)
		res++;
	return (res);
}
