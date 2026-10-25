/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbohdanc <zbohdanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 17:22:20 by zbohdanc          #+#    #+#             */
/*   Updated: 2026/09/01 15:27:19 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"
#include "sorting_helper.h"
#include "libft.h"
#include "stack.h"
#include "types.h"
#include "print_benchmark.h"
#include "parse_flags.h"
#include "parse_numbers.h"

int	main(int argc, char **argv)
{
	int			start;
	t_stack		*a;
	t_flags		flags;
	int			*operations;
	float		disorder;

	if (argc <= 1)
		return (1);
	start = parse_flags(&flags, argc, argv);
	a = stack_init();
	operations = (int *) malloc((OPERATION_COUNT + 1) * sizeof(int));
	if (!parse_numbers(a, start, argc, argv))
	{
		ft_putendl_fd("Error", 2);
		clear_stack(&a);
		return (1);
	}
	disorder = compute_disorder(a, a->len);
	operations[OPERATION_COUNT] = sort(a, flags.strategy, disorder, operations);
	if (flags.benchmark)
		print_benchmark(disorder, flags.strategy, operations);
	clear_stack(&a);
	return (0);
}
