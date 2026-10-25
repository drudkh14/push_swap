/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_helper.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kateslia <kateslia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 19:25:34 by kateslia          #+#    #+#             */
/*   Updated: 2026/08/31 19:25:37 by kateslia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_HELPER_H
# define SORTING_HELPER_H

# include "types.h"

# include <stdlib.h>

float	compute_disorder(t_stack *a, size_t size);

int		ext_to_a(t_stack *a, t_stack *b, size_t index, int *operations);
int		ext_to_a_reset(t_stack *a, t_stack *b, size_t index, int *operations);
int		ext_to_b(t_stack *a, t_stack *b, size_t index, int *operations);
int		ext_to_b_reset(t_stack *a, t_stack *b, size_t index, int *operations);

#endif
