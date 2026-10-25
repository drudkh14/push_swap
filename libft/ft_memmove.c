/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbohdanc <zbohdanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:20:49 by zbohdanc          #+#    #+#             */
/*   Updated: 2026/06/03 12:11:50 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest < src)
		dest = ft_memcpy(dest, src, n);
	else
	{
		i = n;
		while (i > 0)
		{
			*((char *) dest + i - 1) = *((char *) src + i - 1);
			i--;
		}
	}
	return (dest);
}
