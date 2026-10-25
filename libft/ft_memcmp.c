/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbohdanc <zbohdanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 13:54:03 by zbohdanc          #+#    #+#             */
/*   Updated: 2026/06/03 14:32:16 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && *((unsigned char *) s1) == *((unsigned char *) s2))
	{
		i++;
		s1 = (unsigned char *) s1 + 1;
		s2 = (unsigned char *) s2 + 1;
	}
	if (i == n)
		return (0);
	return ((int)(*((unsigned char *) s1) - *((unsigned char *) s2)));
}
