/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kateslia <kateslia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 17:31:42 by kateslia          #+#    #+#             */
/*   Updated: 2026/09/01 16:10:20 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_numbers.h"
#include "libft.h"
#include "ps_atoi.h"
#include "stack.h"

static char	**get_numbers_arr(int start, int argc, char **argv);
static void	free_str_arr(char **arr);
static int	check_duplicates(t_stack *stack);

int	parse_numbers(t_stack *stack, int start, int argc, char **argv)
{
	char	**nums_arr;
	int		i;
	int		success;

	nums_arr = get_numbers_arr(start, argc, argv);
	if (!nums_arr || !*nums_arr)
		return (0);
	i = 0;
	while (nums_arr[i])
	{
		add_back(stack, create_node(ps_atoi(&success, nums_arr[i])));
		if (!success)
		{
			free_str_arr(nums_arr);
			return (0);
		}
		i++;
	}
	free_str_arr(nums_arr);
	return (check_duplicates(stack));
}

static int	check_duplicates(t_stack *stack)
{
	t_node	*i;
	t_node	*j;
	int		curr;

	i = stack->head;
	while (i)
	{
		curr = i->value;
		j = i->next;
		while (j)
		{
			if (j->value == curr)
				return (0);
			j = j->next;
		}
		i = i->next;
	}
	return (1);
}

static char	**get_numbers_arr(int start, int argc, char **argv)
{
	char	**res;
	char	*nums_joined;
	char	*tmp;

	nums_joined = (char *) malloc(1);
	*nums_joined = '\0';
	while (start < argc)
	{
		tmp = nums_joined;
		nums_joined = ft_strjoin(nums_joined, argv[start]);
		free(tmp);
		if (start != argc - 1)
		{
			tmp = nums_joined;
			nums_joined = ft_strjoin(nums_joined, " ");
			free(tmp);
		}
		start++;
	}
	res = ft_split(nums_joined, ' ');
	free(nums_joined);
	return (res);
}

static void	free_str_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
