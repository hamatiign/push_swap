/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkajikaw <kkajikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 20:42:32 by nkato             #+#    #+#             */
/*   Updated: 2026/09/17 19:03:28 by kkajikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static int	check_same_char(char *base)
{
	size_t	i;
	size_t	j;
	size_t	base_size;

	i = 0;
	base_size = ft_strlen(base);
	while (i < base_size - 1)
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_base_error(char *base)
{
	size_t	i;

	i = 0;
	if (ft_strlen(base) <= 1)
		return (1);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		i++;
	}
	if (check_same_char(base))
		return (1);
	return (0);
}

static int	putnbr_base_recursion(int fd, char *base, size_t base_len,
		uintptr_t nbr)
{
	uintptr_t	quotient;
	uintptr_t	remainder;
	char		c;
	int			count;
	int			result;

	quotient = nbr / base_len;
	remainder = nbr % base_len;
	count = 0;
	if (nbr < base_len)
	{
		c = base[nbr];
		if (write(fd, &c, 1) < 0)
			return (-1);
		return (1);
	}
	result = putnbr_base_recursion(fd, base, base_len, quotient);
	if (result < 0)
		return (-1);
	count += result;
	c = base[remainder];
	if (write(fd, &c, 1) < 0)
		return (-1);
	count++;
	return (count);
}

int	ft_putnbr_base(int fd, uintptr_t nbr, char *base)
{
	size_t	base_len;
	int		result;

	if (check_base_error(base))
		return (-1);
	base_len = ft_strlen(base);
	result = putnbr_base_recursion(fd, base, base_len, nbr);
	if (result < 0)
		return (-1);
	return (result);
}
