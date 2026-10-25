/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbohdanc <zbohdanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 15:08:59 by zbohdanc          #+#    #+#             */
/*   Updated: 2026/09/01 15:09:02 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "restore_stacks.h"
#include "operations.h"

int	restore_stacks_a(t_stack *a, t_stack *b, t_part_res *part_res, int *ops)
{
	int		res;
	size_t	r;
	size_t	pr;

	res = 0;
	r = part_res->rotated;
	pr = part_res->pushed_rotated;
	while (r != a->len && pr != b->len && r && pr)
	{
		res += rrr(a, b, ops);
		r--;
		pr--;
	}
	while (r != a->len && r--)
		res += rra(a, ops);
	while (pr != b->len && pr--)
		res += rrb(b, ops);
	return (res);
}

int	restore_stacks_b(t_stack *a, t_stack *b, t_part_res *part_res, int *ops)
{
	int		res;
	size_t	r;
	size_t	pr;

	res = 0;
	r = part_res->rotated;
	pr = part_res->pushed_rotated;
	while (r != b->len && pr != a->len && r && pr)
	{
		res += rrr(a, b, ops);
		r--;
		pr--;
	}
	while (r != b->len && r--)
		res += rrb(b, ops);
	while (pr != a->len && pr--)
		res += rra(a, ops);
	return (res);
}
