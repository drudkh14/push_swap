/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kateslia <kateslia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 19:43:09 by kateslia          #+#    #+#             */
/*   Updated: 2026/09/02 17:43:39 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_three.h"
#include "operations.h"
#include "sort_two.h"

static int	sort_three_rot(t_stack *a, int *operations);
static int	sort_three_in(t_stack *a, t_stack *b, int *operations);

int	sort_three(t_stack *a, t_stack *b, int *operations)
{
	if (a->len == 3)
		return (sort_three_rot(a, operations));
	else
		return (sort_three_in(a, b, operations));
}

static int	sort_three_rot(t_stack *a, int *operations)
{
	int	res;
	int	top;
	int	mid;
	int	bot;

	res = 0;
	top = a->head->value;
	mid = a->head->next->value;
	bot = a->head->next->next->value;
	if (top > mid && top > bot)
		res += ra(a, operations);
	else if (mid > top && mid > bot)
		res += rra(a, operations);
	res += sort_two(a, operations);
	return (res);
}

static int	sort_three_in(t_stack *a, t_stack *b, int *operations)
{
	int	res;
	int	top;
	int	mid;
	int	bot;

	res = 0;
	top = a->head->value;
	mid = a->head->next->value;
	bot = a->head->next->next->value;
	if (top < mid && mid < bot)
		return (0);
	if (top > mid)
		res += sa(a, operations);
	top = a->head->value;
	mid = a->head->next->value;
	bot = a->head->next->next->value;
	if (mid > bot)
	{
		res += pb(a, b, operations);
		res += sa(a, operations);
		res += pa(a, b, operations);
		res += sort_two(a, operations);
	}
	return (res);
}
