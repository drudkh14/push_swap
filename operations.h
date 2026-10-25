/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbohdanc <zbohdanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 19:38:00 by zbohdanc          #+#    #+#             */
/*   Updated: 2026/08/31 19:51:48 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "types.h"

int	sa(t_stack	*a, int *operations);
int	sb(t_stack	*b, int *operations);
int	ss(t_stack *a, t_stack *b, int *operations);
int	pa(t_stack *a, t_stack *b, int *operations);
int	pb(t_stack *a, t_stack *b, int *operations);
int	ra(t_stack *a, int *operations);
int	rb(t_stack *b, int *operations);
int	rr(t_stack *a, t_stack *b, int *operations);
int	rra(t_stack *a, int *operations);
int	rrb(t_stack *b, int *operations);
int	rrr(t_stack *a, t_stack *b, int *operations);

#endif
