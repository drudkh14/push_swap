/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kateslia <kateslia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 19:42:00 by kateslia          #+#    #+#             */
/*   Updated: 2026/08/31 19:42:01 by kateslia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "small_sorting.h"
#include "operations.h"
#include "sort_three.h"
#include "sort_two.h"
#include "sort_four_five.h"

int	sort_small(t_stack *a, t_stack *b, size_t n, int *operations)
{
	if (n == 1)
		return (0);
	else if (n == 2)
		return (sort_two(a, operations));
	else if (n == 3)
		return (sort_three(a, b, operations));
	else
		return (sort_four_five(a, b, n, operations));
}
