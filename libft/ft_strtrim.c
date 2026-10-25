/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbohdanc <zbohdanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:49:02 by zbohdanc          #+#    #+#             */
/*   Updated: 2026/06/03 18:21:39 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;

	start = (char *) s1;
	end = (char *) s1 + (ft_strlen(s1) - 1);
	while (ft_strchr(set, *start))
		start++;
	while (ft_strrchr(set, *end))
		end--;
	return (ft_substr(s1, start - s1, end - start + 1));
}
