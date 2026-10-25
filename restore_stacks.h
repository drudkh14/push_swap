/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_stacks.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbohdanc <zbohdanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 15:08:32 by zbohdanc          #+#    #+#             */
/*   Updated: 2026/09/01 15:08:41 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESTORE_STACKS_H
# define RESTORE_STACKS_H

# include "types.h"

int	restore_stacks_a(t_stack *a, t_stack *b, t_part_res *part_res, int *ops);
int	restore_stacks_b(t_stack *a, t_stack *b, t_part_res *part_res, int *ops);

#endif
