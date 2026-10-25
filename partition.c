/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kateslia <kateslia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 20:06:27 by kateslia          #+#    #+#             */
/*   Updated: 2026/09/02 16:13:17 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "partition.h"
#include "operations.h"
#include "index_stack.h"
#include "routing.h"

static int	*get_pivots(t_stack *stack, size_t n);

int	partition_a(t_stack **stack_arr, size_t n, t_part_res *part_res, int *ops)
{
	int		res;
	int		*pivots;
	size_t	i;

	res = 0;
	pivots = get_pivots(stack_arr[0], n);
	i = 0;
	while ((part_res->pushed + part_res->pushed_rotated != n * 2 / 3) && i < n)
	{
		res += route_a(stack_arr, pivots, part_res, ops);
		i++;
	}
	if (part_res->flag)
		res += rb(stack_arr[1], ops);
	free(pivots);
	return (res);
}

int	partition_b(t_stack **stack_arr, size_t n, t_part_res *part_res, int *ops)
{
	int		res;
	int		*pivots;
	size_t	i;

	res = 0;
	pivots = get_pivots(stack_arr[1], n);
	i = 0;
	while ((part_res->pushed + part_res->pushed_rotated != n - n / 3) && i < n)
	{
		res += route_b(stack_arr, pivots, part_res, ops);
		i++;
	}
	if (part_res->flag)
		res += ra(stack_arr[0], ops);
	free(pivots);
	return (res);
}

static int	*get_pivots(t_stack *stack, size_t n)
{
	int		*res;
	int		*arr;
	size_t	i;
	t_node	*tmp;

	res = (int *) malloc(2 * sizeof(int));
	arr = (int *) malloc(n * sizeof(int));
	i = 0;
	tmp = stack->head;
	while (i < n)
	{
		arr[i++] = tmp->value;
		tmp = tmp->next;
	}
	quick_sort(arr, 0, n - 1);
	res[0] = arr[n / 3];
	res[1] = arr[n * 2 / 3];
	free(arr);
	return (res);
}
