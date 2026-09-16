/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkato <nkato@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 20:29:11 by nkato             #+#    #+#             */
/*   Updated: 2026/08/10 23:03:06 by nkato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static int	ft_putnbr_for_print(int n, int *count);

int	ft_print_int(int n)
{
	int	count;

	count = 0;
	if (n == INT_MIN)
	{
		count = write(STDOUT_FILENO, "-2147483648", 11);
		if (count < 0)
			return (-1);
		return ((int)count);
	}
	if (n < 0)
	{
		if (write(STDOUT_FILENO, "-", 1) < 0)
			return (-1);
		n = -n;
		count++;
	}
	if (ft_putnbr_for_print(n, &count) == -1)
		return (-1);
	return ((int)count);
}

static int	ft_putnbr_for_print(int n, int *count)
{
	char	c;
	ssize_t	result;

	if (n >= 10)
		if (ft_putnbr_for_print(n / 10, count) == -1)
			return (-1);
	c = n % 10 + '0';
	result = write(STDOUT_FILENO, &c, 1);
	if (result < 0)
		return (-1);
	*count += result;
	return (0);
}
