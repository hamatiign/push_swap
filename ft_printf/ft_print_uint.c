/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkajikaw <kkajikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 20:41:09 by nkato             #+#    #+#             */
/*   Updated: 2026/09/16 21:25:39 by kkajikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_uint_rec(int fd, unsigned int n, int *count);

int	ft_print_uint(int fd, unsigned int n)
{
	int	count;

	count = 0;
	if (ft_print_uint_rec(fd, n, &count) == -1)
		return (-1);
	return (count);
}

static int	ft_print_uint_rec(int fd, unsigned int n, int *count)
{
	char	c;
	ssize_t	result;

	if (n >= 10)
		if (ft_print_uint_rec(fd, n / 10, count) == -1)
			return (-1);
	c = n % 10 + '0';
	result = write(fd, &c, 1);
	if (result < 0)
		return (-1);
	*count += result;
	return (0);
}
