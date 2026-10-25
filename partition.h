/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kateslia <kateslia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 20:06:49 by kateslia          #+#    #+#             */
/*   Updated: 2026/08/31 20:06:49 by kateslia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARTITION_H
# define PARTITION_H

# include "types.h"

int	partition_a(t_stack **stack_arr, size_t n, t_part_res *part_res, int *ops);
int	partition_b(t_stack **stack_arr, size_t n, t_part_res *part_res, int *ops);

#endif
