/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbohdanc <zbohdanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 16:31:32 by zbohdanc          #+#    #+#             */
/*   Updated: 2026/06/03 17:31:05 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	min(int a, int b);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	len = min(len, ft_strlen(s) - start);
	res = (char *) malloc(len + 1);
	if (res)
		ft_strlcpy(res, s + start, len + 1);
	return (res);
}

static int	min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}
