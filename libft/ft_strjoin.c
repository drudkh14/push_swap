/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbohdanc <zbohdanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:36:31 by zbohdanc          #+#    #+#             */
/*   Updated: 2026/06/03 17:40:11 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*res;

	size = ft_strlen(s1) + ft_strlen(s2);
	res = (char *) malloc(size + 1);
	if (res)
	{
		ft_strlcpy(res, s1, size + 1);
		ft_strlcat(res, s2, size + 1);
	}
	return (res);
}
