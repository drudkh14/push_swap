/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbohdanc <zbohdanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 18:28:03 by zbohdanc          #+#    #+#             */
/*   Updated: 2026/06/08 18:10:31 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_words(char const *str, char c);
static int	count_word_len(char const *str, char c);
static void	*clean_arr(char **arr);

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		curr_word_len;
	int		res_size;
	int		i;

	res_size = count_words(s, c);
	res = (char **) malloc((res_size + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (i < res_size)
	{
		while (*s == c)
			s++;
		curr_word_len = count_word_len(s, c);
		res[i] = ft_substr(s, 0, curr_word_len);
		if (!res[i])
			return ((char **) clean_arr(res));
		s += curr_word_len;
		i++;
	}
	res[i] = NULL;
	return (res);
}

static int	count_words(char const *str, char c)
{
	int	res;
	int	is_in_word;

	is_in_word = 0;
	res = 0;
	while (*str)
	{
		if (!is_in_word && *str != c)
		{
			is_in_word = 1;
			res++;
		}
		if (is_in_word && *str == c)
			is_in_word = 0;
		str++;
	}
	return (res);
}

static int	count_word_len(char const *str, char c)
{
	int	res;

	res = 0;
	while (*str != c && *str)
	{
		str++;
		res++;
	}
	return (res);
}

static void	*clean_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return ((void *) 0);
}
