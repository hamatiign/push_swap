/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkajikaw <kkajikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 20:36:28 by nkato             #+#    #+#             */
/*   Updated: 2026/09/16 21:24:42 by kkajikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(int fd, void *ptr)
{
	int			count;
	ssize_t		result;
	uintptr_t	address;

	count = 0;
	if (ptr == NULL)
	{
		result = write(fd, "(nil)", 5);
		if (result < 0)
			return (-1);
		return (result);
	}
	address = (uintptr_t)ptr;
	result = write(fd, "0x", 2);
	if (result < 0)
		return (-1);
	count += result;
	result = ft_putnbr_base(fd, address, "0123456789abcdef");
	if (result < 0)
		return (-1);
	count += result;
	return (count);
}
