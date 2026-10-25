/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_benchmark.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbohdanc <zbohdanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 20:03:50 by zbohdanc          #+#    #+#             */
/*   Updated: 2026/09/02 16:43:54 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_benchmark.h"
#include "libft.h"

static void	print_disorder_percent(float disorder);
static char	*get_strategy_str(float disorder, t_strategy strategy);
static void	print_ops_count(t_operation start, t_operation stop, int *ops);
static char	*get_operation_name(t_operation operation);

void	print_benchmark(float dis, t_strategy strat, int *operations)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	print_disorder_percent(dis);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putendl_fd(get_strategy_str(dis, strat), 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(operations[OPERATION_COUNT], 2);
	ft_putendl_fd("", 2);
	ft_putstr_fd("[bench]", 2);
	print_ops_count(OP_SA, OP_PB, operations);
	ft_putstr_fd("[bench]", 2);
	print_ops_count(OP_RA, OP_RRR, operations);
}

static void	print_disorder_percent(float disorder)
{
	int	n;

	n = (int)(disorder * 10000 + 0.5);
	ft_putnbr_fd(n / 100, 2);
	ft_putstr_fd(".", 2);
	if (n % 100 < 10)
		ft_putnbr_fd(0, 2);
	ft_putnbr_fd(n % 100, 2);
	ft_putendl_fd("%", 2);
}

static char	*get_strategy_str(float disorder, t_strategy strategy)
{
	if (strategy == SIMPLE)
		return ("Simple / O(n^2)");
	else if (strategy == MEDIUM)
		return ("Medium / O(n * sqrt(n))");
	else if (strategy == COMPLEX)
		return ("Complex / O(n * log(n))");
	else
	{
		if (disorder < 0.2)
			return ("Adaptive / O(n^2)");
		else if (disorder < 0.5)
			return ("Adaptive / O(n * sqrt(n))");
		else
			return ("Adaptive / O(n * log(n))");
	}
}

static void	print_ops_count(t_operation start, t_operation stop, int *ops)
{
	while (start <= stop)
	{
		ft_putstr_fd(" ", 2);
		ft_putstr_fd(get_operation_name(start), 2);
		ft_putstr_fd(" ", 2);
		ft_putnbr_fd(ops[start], 2);
		if (start != stop)
			ft_putstr_fd(" ", 2);
		start++;
	}
	ft_putendl_fd("", 2);
}

static char	*get_operation_name(t_operation operation)
{
	if (operation == OP_SA)
		return ("sa");
	if (operation == OP_SB)
		return ("sb");
	if (operation == OP_SS)
		return ("ss");
	if (operation == OP_PA)
		return ("pa");
	if (operation == OP_PB)
		return ("pb");
	if (operation == OP_RA)
		return ("ra");
	if (operation == OP_RB)
		return ("rb");
	if (operation == OP_RR)
		return ("rr");
	if (operation == OP_RRA)
		return ("rra");
	if (operation == OP_RRB)
		return ("rrb");
	if (operation == OP_RRR)
		return ("rrr");
	else
		return ("unknown");
}
