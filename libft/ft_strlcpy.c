/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbohdanc <zbohdanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 12:18:14 by zbohdanc          #+#    #+#             */
/*   Updated: 2026/06/03 12:56:58 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	res;
	size_t	i;

	res = ft_strlen(src);
	if (!size)
		return (res);
	i = 0;
	while (i < size - 1 && *src)
	{
		*dest = *src;
		i++;
		src++;
		dest++;
	}
	*dest = '\0';
	return (res);
}
