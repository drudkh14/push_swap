/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kateslia <kateslia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 19:25:09 by kateslia          #+#    #+#             */
/*   Updated: 2026/09/01 15:27:34 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"
#include "stack.h"
#include "insertion_sort.h"
#include "chunk_sort.h"
#include "quick_sort.h"

static int	choose_sort(t_stack *a, t_stack *b, float disorder, int *ops);

int	sort(t_stack *a, t_strategy strategy, float disorder, int *operations)
{
	t_stack	*b;
	int		res;

	if (disorder == 0.0)
		return (0);
	b = stack_init();
	if (strategy == SIMPLE)
		res = insertion_sort(a, b, operations);
	else if (strategy == MEDIUM)
		res = chunk_sort(a, b, operations);
	else if (strategy == COMPLEX)
		res = quick_sort_a(a, b, a->len, operations);
	else
		res = choose_sort(a, b, disorder, operations);
	clear_stack(&b);
	return (res);
}

static int	choose_sort(t_stack *a, t_stack *b, float disorder, int *ops)
{
	if (disorder < 0.2)
		return (insertion_sort(a, b, ops));
	else if (disorder < 0.5)
		return (chunk_sort(a, b, ops));
	else
		return (quick_sort_a(a, b, a->len, ops));
}
