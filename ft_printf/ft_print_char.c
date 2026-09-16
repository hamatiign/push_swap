/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkato <nkato@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 16:54:30 by nkato             #+#    #+#             */
/*   Updated: 2026/08/10 23:03:04 by nkato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	char	ch;
	ssize_t	result;

	ch = (char)c;
	result = write(STDOUT_FILENO, &ch, 1);
	if (result < 0)
		return (-1);
	return ((int)result);
}
