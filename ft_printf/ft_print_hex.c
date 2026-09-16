/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkajikaw <kkajikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 20:41:28 by nkato             #+#    #+#             */
/*   Updated: 2026/09/16 21:22:48 by kkajikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(int fd, unsigned int n, char specifier)
{
	if (specifier == 'x')
		return (ft_putnbr_base(fd, (uintptr_t)n, "0123456789abcdef"));
	return (ft_putnbr_base(fd, (uintptr_t)n, "0123456789ABCDEF"));
}
