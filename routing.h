/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbohdanc <zbohdanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 15:46:59 by zbohdanc          #+#    #+#             */
/*   Updated: 2026/09/02 15:48:21 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTING_H
# define ROUTING_H

# include "types.h"

int	route_a(t_stack **s_arr, int *pivs, t_part_res *part_res, int *ops);
int	route_b(t_stack **s_arr, int *pivs, t_part_res *part_res, int *ops);

#endif
