/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkato <nkato@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 20:36:39 by nkato             #+#    #+#             */
/*   Updated: 2026/08/10 23:02:59 by nkato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *str)
{
	size_t	len;
	ssize_t	result;

	if (str == NULL)
		str = "(null)";
	len = 0;
	while (str[len] != '\0')
		len++;
	result = write(STDOUT_FILENO, str, len);
	if (result < 0)
		return (-1);
	return ((int)result);
}
