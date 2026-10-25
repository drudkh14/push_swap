/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kateslia <kateslia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 17:29:40 by kateslia          #+#    #+#             */
/*   Updated: 2026/09/01 16:10:11 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_flags.h"
#include "libft.h"

static int	ft_strcmp(const char *s1, const char *s2);
static void	get_strategy(t_strategy *strategy, const char *s, int *start);

int	parse_flags(t_flags *flags, int argc, char **argv)
{
	int	start;
	int	i;

	flags->benchmark = 0;
	flags->strategy = ADAPTIVE;
	start = 1;
	i = 1;
	while (i < argc && argv[i][0] == '-')
	{
		if (!ft_strcmp("--bench", argv[i]))
		{
			flags->benchmark = 1;
			start++;
		}
		else
			get_strategy(&(flags->strategy), argv[i], &start);
		i++;
	}
	return (start);
}

static void	get_strategy(t_strategy *strategy, const char *s, int *start)
{
	if (!ft_strcmp("--simple", s))
	{
		(*start)++;
		*strategy = SIMPLE;
	}
	else if (!ft_strcmp("--medium", s))
	{
		(*start)++;
		*strategy = MEDIUM;
	}
	else if (!ft_strcmp("--complex", s))
	{
		(*start)++;
		*strategy = COMPLEX;
	}
	else if (!ft_strcmp("--adaptive", s))
	{
		(*start)++;
		*strategy = ADAPTIVE;
	}
}

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && ((unsigned char) *s1 == (unsigned char) *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char) *s1 - (unsigned char) *s2);
}
