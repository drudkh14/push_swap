/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kateslia <kateslia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 18:57:32 by kateslia          #+#    #+#             */
/*   Updated: 2026/08/31 18:57:33 by kateslia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

# include "types.h"

t_stack	*stack_init(void);
void	clear_stack(t_stack **stack_p);

t_node	*create_node(int value);
void	add_front(t_stack *stack, t_node *node);
void	add_back(t_stack *stack, t_node *node);
t_node	*pop_front(t_stack *stack);
t_node	*pop_back(t_stack *stack);
t_node	*get_node(t_stack *stack, size_t index);

size_t	find_index_minimum(t_stack *stack, size_t n);
size_t	find_index_maximum(t_stack *stack, size_t n);

void	visualize_stack(t_stack *stack);

#endif
