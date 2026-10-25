/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbohdanc <zbohdanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 15:11:41 by zbohdanc          #+#    #+#             */
/*   Updated: 2026/09/01 15:11:56 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_three_b.h"
#include "sort_two_b.h"
#include "operations.h"

static int	sort_three_b_in(t_stack *a, t_stack *b, int *operations);
static int	sort_three_b_rot(t_stack *a, t_stack *b, int *operations);

int	sort_three_b(t_stack *a, t_stack *b, int *operations)
{
	if (b->len == 3)
		return (sort_three_b_rot(a, b, operations));
	else
		return (sort_three_b_in(a, b, operations));
}

static int	sort_three_b_rot(t_stack *a, t_stack *b, int *operations)
{
	int	res;
	int	top;
	int	mid;
	int	bot;

	res = 0;
	top = b->head->value;
	mid = b->head->next->value;
	bot = b->head->next->next->value;
	if (mid > bot && mid > top)
		res += rb(b, operations);
	else if (bot > mid && bot > top)
		res += rrb(b, operations);
	res += pa(a, b, operations);
	if (b->head->value < b->head->next->value)
		res += sb(b, operations);
	res += pa(a, b, operations);
	res += pa(a, b, operations);
	return (res);
}

static int	sort_three_b_in(t_stack *a, t_stack *b, int *operations)
{
	int	res;
	int	top;
	int	mid;
	int	bot;

	res = 0;
	top = b->head->value;
	mid = b->head->next->value;
	bot = b->head->next->next->value;
	if (top > mid && top > bot)
		res += pa(a, b, operations) + sort_two_b(a, b, operations);
	else if (mid > top && mid > bot)
	{
		res += sb(b, operations) + pa(a, b, operations);
		res += sort_two_b(a, b, operations);
	}
	else
	{
		if (b->head->value < b->head->next->value)
			res += sb(b, operations);
		res += pa(a, b, operations) + sb(b, operations);
		res += pa(a, b, operations) + sa(a, operations);
		res += pa(a, b, operations);
	}
	return (res);
}
