/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkajikaw <kkajikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 16:54:30 by nkato             #+#    #+#             */
/*   Updated: 2026/09/16 21:20:40 by kkajikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int fd, int c)
{
	char	ch;
	ssize_t	result;

	ch = (char)c;
	result = write(fd, &ch, 1);
	if (result < 0)
		return (-1);
	return ((int)result);
}
