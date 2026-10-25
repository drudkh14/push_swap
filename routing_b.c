/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routing_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbohdanc <zbohdanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 15:54:32 by zbohdanc          #+#    #+#             */
/*   Updated: 2026/09/02 16:07:56 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routing.h"
#include "operations.h"

static int	route_top(t_stack **s_arr, t_part_res *part_res, int *ops);
static int	route_mid(t_stack **s_arr, t_part_res *part_res, int *ops);
static int	route_bot(t_stack **s_arr, t_part_res *part_res, int *ops);

int	route_b(t_stack **s_arr, int *pivs, t_part_res *part_res, int *ops)
{
	if (s_arr[1]->head->value >= pivs[1])
		return (route_top(s_arr, part_res, ops));
	else if (s_arr[1]->head->value >= pivs[0])
		return (route_mid(s_arr, part_res, ops));
	else
		return (route_bot(s_arr, part_res, ops));
}

static int	route_top(t_stack **s_arr, t_part_res *part_res, int *ops)
{
	int	res;

	res = 0;
	if (part_res->flag)
		res += ra(s_arr[0], ops);
	part_res->flag = 0;
	res += pa(s_arr[0], s_arr[1], ops);
	part_res->pushed++;
	return (res);
}

static int	route_mid(t_stack **s_arr, t_part_res *part_res, int *ops)
{
	int	res;

	res = 0;
	if (part_res->flag)
		res += ra(s_arr[0], ops);
	part_res->flag = 1;
	res += pa(s_arr[0], s_arr[1], ops);
	part_res->pushed_rotated++;
	return (res);
}

static int	route_bot(t_stack **s_arr, t_part_res *part_res, int *ops)
{
	int	res;

	res = 0;
	if (part_res->flag)
		res += rr(s_arr[0], s_arr[1], ops);
	else
		res += rb(s_arr[1], ops);
	part_res->flag = 0;
	part_res->rotated++;
	return (res);
}
