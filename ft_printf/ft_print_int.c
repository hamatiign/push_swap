/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkajikaw <kkajikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 20:29:11 by nkato             #+#    #+#             */
/*   Updated: 2026/09/16 21:23:53 by kkajikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static int	ft_putnbr_for_print(int fd, int n, int *count);

int	ft_print_int(int fd, int n)
{
	int	count;

	count = 0;
	if (n == INT_MIN)
	{
		count = write(fd, "-2147483648", 11);
		if (count < 0)
			return (-1);
		return ((int)count);
	}
	if (n < 0)
	{
		if (write(fd, "-", 1) < 0)
			return (-1);
		n = -n;
		count++;
	}
	if (ft_putnbr_for_print(fd, n, &count) == -1)
		return (-1);
	return ((int)count);
}

static int	ft_putnbr_for_print(int fd, int n, int *count)
{
	char	c;
	ssize_t	result;

	if (n >= 10)
		if (ft_putnbr_for_print(fd, n / 10, count) == -1)
			return (-1);
	c = n % 10 + '0';
	result = write(fd, &c, 1);
	if (result < 0)
		return (-1);
	*count += result;
	return (0);
}
