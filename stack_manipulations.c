/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kateslia <kateslia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 19:11:51 by kateslia          #+#    #+#             */
/*   Updated: 2026/09/02 17:43:25 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	clear_stack(t_stack **stack_p)
{
	t_node	*tmp;
	t_node	*head;

	head = (*stack_p)->head;
	free(*stack_p);
	*stack_p = NULL;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

size_t	find_index_minimum(t_stack *stack, size_t n)
{
	size_t	minimum;
	size_t	i;

	minimum = 0;
	i = 1;
	while (i < n && i < stack->len)
	{
		if (get_node(stack, i)->value < get_node(stack, minimum)->value)
			minimum = i;
		i++;
	}
	return (minimum);
}

size_t	find_index_maximum(t_stack *stack, size_t n)
{
	size_t	maximum;
	size_t	i;

	maximum = 0;
	i = 1;
	while (i < n && i < stack->len)
	{
		if (get_node(stack, i)->value > get_node(stack, maximum)->value)
			maximum = i;
		i++;
	}
	return (maximum);
}

t_node	*create_node(int value)
{
	t_node	*new;

	new = (t_node *) malloc(sizeof(t_node));
	if (!new)
		return (new);
	new->prev = NULL;
	new->next = NULL;
	new->value = value;
	return (new);
}

t_node	*get_node(t_stack *stack, size_t index)
{
	t_node	*tmp;

	if (index >= stack->len)
		return (NULL);
	if (!stack->head)
		return (NULL);
	tmp = stack->head;
	while (tmp && index-- > 0)
		tmp = tmp->next;
	return (tmp);
}
