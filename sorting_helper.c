/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kateslia <kateslia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 19:25:28 by kateslia          #+#    #+#             */
/*   Updated: 2026/08/31 19:25:31 by kateslia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting_helper.h"
#include "operations.h"
#include "stack.h"

float	compute_disorder(t_stack *stack, size_t size)
{
	int		mistakes;
	int		total_pairs;
	size_t	i;
	size_t	j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs++;
			if (get_node(stack, i)->value > get_node(stack, j)->value)
				mistakes++;
			j++;
		}
		i++;
	}
	return ((float) mistakes / total_pairs);
}

int	ext_to_a(t_stack *a, t_stack *b, size_t index, int *operations)
{
	size_t	i;
	int		res;

	res = 0;
	i = 0;
	if (index <= b->len / 2)
		while (i++ < index)
			res += rb(b, operations);
	else
		while (i++ < (b->len - index))
			res += rrb(b, operations);
	res += pa(a, b, operations);
	return (res);
}

int	ext_to_b(t_stack *a, t_stack *b, size_t index, int *operations)
{
	size_t	i;
	int		res;

	res = 0;
	i = 0;
	if (index <= a->len / 2)
	{
		while (i++ < index)
			res += ra(a, operations);
	}
	else
	{
		while (i++ < (a->len - index))
			res += rra(a, operations);
	}
	res += pb(a, b, operations);
	return (res);
}

int	ext_to_a_reset(t_stack *a, t_stack *b, size_t index, int *operations)
{
	size_t	i;
	int		res;

	res = 0;
	i = 0;
	while (i < index && index != 1)
	{
		res += rb(b, operations);
		i++;
	}
	if (index == 1)
		res += sb(b, operations);
	res += pa(a, b, operations);
	while (i--)
		res += rrb(b, operations);
	return (res);
}

int	ext_to_b_reset(t_stack *a, t_stack *b, size_t index, int *operations)
{
	size_t	i;
	int		res;

	res = 0;
	i = 0;
	while (i < index && index != 1)
	{
		res += ra(a, operations);
		i++;
	}
	if (index == 1)
		res += sa(a, operations);
	res += pb(a, b, operations);
	while (i--)
		res += rra(a, operations);
	return (res);
}
