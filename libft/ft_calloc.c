/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbohdanc <zbohdanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 15:34:13 by zbohdanc          #+#    #+#             */
/*   Updated: 2026/06/03 16:14:01 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	if (nmemb != 0 && size > (size_t) -1 / nmemb)
		return ((void *) 0);
	res = malloc(nmemb * size);
	if (nmemb != 0 && size != 0 && res != NULL)
		ft_bzero(res, nmemb * size);
	return (res);
}
