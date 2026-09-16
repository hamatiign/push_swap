/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkato <nkato@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 20:41:28 by nkato             #+#    #+#             */
/*   Updated: 2026/08/10 23:03:03 by nkato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int n, char specifier)
{
	if (specifier == 'x')
		return (ft_putnbr_base((uintptr_t)n, "0123456789abcdef"));
	return (ft_putnbr_base((uintptr_t)n, "0123456789ABCDEF"));
}
