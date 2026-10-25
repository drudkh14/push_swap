/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kateslia <kateslia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 18:20:52 by kateslia          #+#    #+#             */
/*   Updated: 2026/09/02 16:45:04 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_atoi.h"

static int	get_num(char const *s, long *res);

int	ps_atoi(int *success, char const *s)
{
	long	res;
	int		sign;

	*success = 1;
	res = 0;
	sign = 1;
	while (*s == ' ')
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	if (!*s)
		*success = 0;
	if (!get_num(s, &res))
	{
		*success = 0;
		return (0);
	}
	if (res * sign < -2147483648 || res * sign > 2147483647)
		*success = 0;
	res *= sign;
	return (res);
}

static int	get_num(char const *s, long *res)
{
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		*res = *res * 10 + (*s - '0');
		s++;
	}
	return (1);
}
