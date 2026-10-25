/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kateslia <kateslia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 18:57:26 by kateslia          #+#    #+#             */
/*   Updated: 2026/09/02 17:43:04 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = (t_stack *) malloc(sizeof(t_stack));
	if (!stack)
		return (stack);
	stack->head = NULL;
	stack->tail = NULL;
	stack->len = 0;
	return (stack);
}

void	add_front(t_stack *stack, t_node *node)
{
	if (!node)
		return ;
	node->prev = NULL;
	if (!stack->head)
	{
		stack->head = node;
		stack->tail = node;
	}
	else
	{
		node->next = stack->head;
		stack->head->prev = node;
		stack->head = node;
	}
	stack->len++;
}

void	add_back(t_stack *stack, t_node *node)
{
	if (!node)
		return ;
	node->next = NULL;
	if (!stack->head)
	{
		stack->head = node;
		stack->tail = node;
	}
	else
	{
		node->prev = stack->tail;
		stack->tail->next = node;
		stack->tail = node;
	}
	stack->len++;
}

t_node	*pop_front(t_stack *stack)
{
	t_node	*tmp;

	if (!stack->head)
		return (NULL);
	tmp = stack->head;
	stack->head = stack->head->next;
	if (!stack->head)
		stack->tail = NULL;
	else
		stack->head->prev = NULL;
	tmp->prev = NULL;
	tmp->next = NULL;
	stack->len--;
	return (tmp);
}

t_node	*pop_back(t_stack *stack)
{
	t_node	*tmp;

	if (!stack->head)
		return (NULL);
	tmp = stack->tail;
	stack->tail = stack->tail->prev;
	if (!stack->tail)
		stack->head = NULL;
	else
		stack->tail->next = NULL;
	tmp->prev = NULL;
	tmp->next = NULL;
	stack->len--;
	return (tmp);
}
