/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_disorder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkajikaw <kkajikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 01:11:53 by kkajikaw          #+#    #+#             */
/*   Updated: 2026/09/18 01:12:26 by kkajikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_disorder(double disorder)
{
	int	value;
	int	integer_part;
	int	decimal_part;

	value = (int)((disorder + 0.00005) * 10000);
	ft_printf_fd(STDERR_FILENO, "disorder: ");
	integer_part = value / 100;
	decimal_part = value % 100;
	ft_printf_fd(STDERR_FILENO, "%i.", integer_part);
	if (decimal_part < 10)
		ft_printf_fd(STDERR_FILENO, "0");
	ft_printf_fd(STDERR_FILENO, "%i%%\n", decimal_part);
}