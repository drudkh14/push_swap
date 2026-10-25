/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbohdanc <zbohdanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 17:43:03 by zbohdanc          #+#    #+#             */
/*   Updated: 2026/06/04 18:43:51 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_digits(int n);
static void	write_digits_in_tab(char *tab, int n, int pos);

char	*ft_itoa(int n)
{
	char	*res;
	int		len;

	if (n == 0)
	{
		res = ft_strdup("0\0");
		return (res);
	}
	if (n == -2147483648)
	{
		res = ft_strdup("-2147483648");
		return (res);
	}
	len = count_digits(n) + (n < 0) + 1;
	res = (char *) malloc(len);
	if (!res)
		return (res);
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	write_digits_in_tab(res, n, len - 2);
	res[len - 1] = '\0';
	return (res);
}

static int	count_digits(int n)
{
	if (n < 0)
		n = -n;
	if (n == 0)
		return (0);
	return (1 + count_digits(n / 10));
}

static void	write_digits_in_tab(char *tab, int n, int pos)
{
	if (n != 0)
	{
		write_digits_in_tab(tab, n / 10, pos - 1);
		tab[pos] = '0' + n % 10;
	}
}
