/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kateslia <kateslia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 20:02:56 by kateslia          #+#    #+#             */
/*   Updated: 2026/08/31 20:02:57 by kateslia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUICK_SORT_H
# define QUICK_SORT_H

# include <stdlib.h>

# include "types.h"

int	quick_sort_a(t_stack *a, t_stack *b, size_t len, int *operations);

#endif
