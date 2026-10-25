/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kateslia <kateslia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 20:01:45 by kateslia          #+#    #+#             */
/*   Updated: 2026/09/02 17:42:53 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quick_sort.h"
#include "sorting_helper.h"
#include "small_sorting.h"
#include "small_sorting_b.h"
#include "operations.h"
#include "partition.h"
#include "restore_stacks.h"

static int			quick_sort_b(t_stack *a, t_stack *b, size_t n, int *ops);
static size_t		get_rotated(size_t n, t_part_res *part_res);
static int			reversed_push_to_a(t_stack **stack_arr, size_t n, int *ops);
static t_part_res	*initialize_part_res(void);

int	quick_sort_a(t_stack *a, t_stack *b, size_t n, int *operations)
{
	int			res;
	t_part_res	*part_res;
	t_stack		*stack_arr[2];

	res = 0;
	if (compute_disorder(a, n) == 0.0)
		return (res);
	if (n <= 5)
		return (sort_small(a, b, n, operations));
	part_res = initialize_part_res();
	stack_arr[0] = a;
	stack_arr[1] = b;
	res += partition_a(stack_arr, n, part_res, operations);
	res += restore_stacks_a(a, b, part_res, operations);
	res += quick_sort_a(a, b, get_rotated(n, part_res), operations);
	res += quick_sort_b(a, b, part_res->pushed_rotated, operations);
	res += quick_sort_b(a, b, part_res->pushed, operations);
	free(part_res);
	return (res);
}

static int	quick_sort_b(t_stack *a, t_stack *b, size_t n, int *operations)
{
	int			res;
	t_part_res	*part_res;
	t_stack		*stack_arr[2];

	res = 0;
	stack_arr[0] = a;
	stack_arr[1] = b;
	if (compute_disorder(b, n) == 1.0)
	{
		while ((int) n--)
			res += pa(a, b, operations);
		return (res);
	}
	if (n <= 5)
		return (sort_small_b(a, b, n, operations));
	if (compute_disorder(b, n) == 0.0 && b->len == n)
		return (reversed_push_to_a(stack_arr, n, operations));
	part_res = initialize_part_res();
	res += partition_b(stack_arr, n, part_res, operations);
	res += quick_sort_a(a, b, part_res->pushed, operations);
	res += restore_stacks_b(a, b, part_res, operations);
	res += quick_sort_a(a, b, part_res->pushed_rotated, operations);
	res += quick_sort_b(a, b, get_rotated(n, part_res), operations);
	free(part_res);
	return (res);
}

static size_t	get_rotated(size_t n, t_part_res *part_res)
{
	return (n - part_res->pushed - part_res->pushed_rotated);
}

static int	reversed_push_to_a(t_stack **stack_arr, size_t n, int *ops)
{
	int	res;

	res = 0;
	while ((int) n--)
	{
		res += rrb(stack_arr[1], ops);
		res += pa(stack_arr[0], stack_arr[1], ops);
	}
	return (res);
}

static t_part_res	*initialize_part_res(void)
{
	t_part_res	*res;

	res = (t_part_res *) malloc(sizeof(t_part_res));
	res->pushed = 0;
	res->pushed_rotated = 0;
	res->rotated = 0;
	res->flag = 0;
	return (res);
}
