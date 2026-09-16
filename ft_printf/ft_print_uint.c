/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkato <nkato@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 20:41:09 by nkato             #+#    #+#             */
/*   Updated: 2026/08/10 23:02:57 by nkato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_uint_rec(unsigned int n, int *count);

int	ft_print_uint(unsigned int n)
{
	int	count;

	count = 0;
	if (ft_print_uint_rec(n, &count) == -1)
		return (-1);
	return (count);
}

static int	ft_print_uint_rec(unsigned int n, int *count)
{
	char	c;
	ssize_t	result;

	if (n >= 10)
		if (ft_print_uint_rec(n / 10, count) == -1)
			return (-1);
	c = n % 10 + '0';
	result = write(STDOUT_FILENO, &c, 1);
	if (result < 0)
		return (-1);
	*count += result;
	return (0);
}
