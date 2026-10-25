/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kateslia <kateslia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 19:42:15 by kateslia          #+#    #+#             */
/*   Updated: 2026/08/31 19:42:16 by kateslia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_four_five.h"
#include "operations.h"
#include "stack.h"
#include "sorting_helper.h"
#include "sort_three.h"

int	sort_four_five(t_stack *a, t_stack *b, size_t n, int *operations)
{
	int		res;
	size_t	i;

	res = 0;
	i = n;
	while (i > 3)
	{
		if (a->len == i)
			res += ext_to_b(a, b, find_index_minimum(a, a->len), operations);
		else
			res += ext_to_b_reset(a, b, find_index_minimum(a, i), operations);
		i--;
	}
	res += sort_three(a, b, operations);
	while (i++ != n)
		res += pa(a, b, operations);
	return (res);
}
