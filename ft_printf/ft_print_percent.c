/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkajikaw <kkajikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 20:40:57 by nkato             #+#    #+#             */
/*   Updated: 2026/09/16 21:24:09 by kkajikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_percent(int fd)
{
	ssize_t	result;

	result = write(fd, "%%", 1);
	if (result < 0)
		return (-1);
	return ((int)result);
}
