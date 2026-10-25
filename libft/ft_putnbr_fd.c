/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbohdanc <zbohdanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 19:27:23 by zbohdanc          #+#    #+#             */
/*   Updated: 2026/06/03 19:39:30 by zbohdanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void	putnbr_rec_fd(int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		putnbr_rec_fd(-n, fd);
	}
	else if (n == 0)
	{
		write(fd, "0", 1);
	}
	else
	{
		putnbr_rec_fd(n, fd);
	}
}

static void	putnbr_rec_fd(int n, int fd)
{
	char	curr_dig;

	if (n > 0)
	{
		putnbr_rec_fd(n / 10, fd);
		curr_dig = '0' + n % 10;
		write(fd, &curr_dig, 1);
	}
}
