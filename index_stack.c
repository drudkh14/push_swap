/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kateslia <kateslia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 18:20:20 by kateslia          #+#    #+#             */
/*   Updated: 2026/08/31 18:20:22 by kateslia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index_stack.h"

static int	binary_search_index(int *arr, int p, int r, int value);
void		quick_sort(int *arr, int p, int r);
static int	partition(int *arr, int p, int r);

void	index_stack(t_stack *stack)
{
	int		*arr;
	t_node	*tmp;
	int		i;

	arr = (int *) malloc(stack->len * sizeof(int));
	tmp = stack->head;
	i = 0;
	while (tmp)
	{
		arr[i] = tmp->value;
		i++;
		tmp = tmp->next;
	}
	quick_sort(arr, 0, stack->len - 1);
	tmp = stack->head;
	while (tmp)
	{
		tmp->value = binary_search_index(arr, 0, stack->len - 1, tmp->value);
		tmp = tmp->next;
	}
	free(arr);
}

static int	binary_search_index(int *arr, int p, int r, int value)
{
	int	q;

	if (p > r)
		return (-1);
	q = (p + r) / 2;
	if (arr[q] == value)
		return (q);
	if (arr[q] < value)
		return (binary_search_index(arr, q + 1, r, value));
	return (binary_search_index(arr, p, q - 1, value));
}

void	quick_sort(int *arr, int p, int r)
{
	int	q;

	if (p > r)
		return ;
	q = partition(arr, p, r);
	quick_sort(arr, p, q - 1);
	quick_sort(arr, q + 1, r);
}

static int	partition(int *arr, int p, int r)
{
	int	u;
	int	q;
	int	tmp;

	q = p;
	u = p;
	while (u < r)
	{
		if (arr[u] <= arr[r])
		{
			tmp = arr[q];
			arr[q] = arr[u];
			arr[u] = tmp;
			q++;
		}
		u++;
	}
	tmp = arr[q];
	arr[q] = arr[r];
	arr[r] = tmp;
	return (q);
}
