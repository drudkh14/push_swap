/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbohdanc <zbohdanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:37:33 by zbohdanc          #+#    #+#             */
/*   Updated: 2026/06/04 17:19:52 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*tmp_big;
	char	*tmp_little;
	size_t	buff_len;

	if (!(*little))
		return ((char *) big);
	while (*big && len > 0)
	{
		tmp_big = (char *) big;
		tmp_little = (char *) little;
		buff_len = len;
		while (*tmp_little && *tmp_big && *tmp_little == *tmp_big)
		{
			tmp_little++;
			tmp_big++;
			if (!(buff_len > 0))
				return ((void *) 0);
			buff_len--;
		}
		if (!(*tmp_little))
			return ((char *) big);
		len--;
		big++;
	}
	return ((void *) 0);
}
