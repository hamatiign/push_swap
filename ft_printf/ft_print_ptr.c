/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkato <nkato@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 20:36:28 by nkato             #+#    #+#             */
/*   Updated: 2026/08/10 23:03:00 by nkato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	int			count;
	ssize_t		result;
	uintptr_t	address;

	count = 0;
	if (ptr == NULL)
	{
		result = write(STDOUT_FILENO, "(nil)", 5);
		if (result < 0)
			return (-1);
		return (result);
	}
	address = (uintptr_t)ptr;
	result = write(STDOUT_FILENO, "0x", 2);
	if (result < 0)
		return (-1);
	count += result;
	result = ft_putnbr_base(address, "0123456789abcdef");
	if (result < 0)
		return (-1);
	count += result;
	return (count);
}
