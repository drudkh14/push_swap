/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kateslia <kateslia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 19:43:26 by kateslia          #+#    #+#             */
/*   Updated: 2026/08/31 19:43:27 by kateslia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_two.h"
#include "operations.h"

int	sort_two(t_stack *stack, int *operations)
{
	if (stack->head->value > stack->head->next->value)
		return (sa(stack, operations));
	return (0);
}
