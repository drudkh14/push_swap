/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorting_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbohdanc <zbohdanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 15:10:08 by zbohdanc          #+#    #+#             */
/*   Updated: 2026/09/01 15:10:22 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "small_sorting_b.h"
#include "sort_two_b.h"
#include "sort_three_b.h"
#include "sort_four_five_b.h"

int	sort_small_b(t_stack *a, t_stack *b, size_t n, int *operations)
{
	if (n == 1)
		return (0);
	else if (n == 2)
		return (sort_two_b(a, b, operations));
	else if (n == 3)
		return (sort_three_b(a, b, operations));
	else
		return (sort_four_five_b(a, b, n, operations));
}
