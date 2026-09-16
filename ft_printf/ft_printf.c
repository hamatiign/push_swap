/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkato <nkato@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 11:32:03 by nkato             #+#    #+#             */
/*   Updated: 2026/08/10 23:02:55 by nkato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	handle_arg(va_list *ap, char c)
{
	if (c == 'd' || c == 'i')
		return (ft_print_int(va_arg(*ap, int)));
	if (c == 'u')
		return (ft_print_uint(va_arg(*ap, unsigned int)));
	if (c == 'c')
		return (ft_print_char(va_arg(*ap, int)));
	if (c == 's')
		return (ft_print_string(va_arg(*ap, char *)));
	if (c == 'p')
		return (ft_print_ptr(va_arg(*ap, void *)));
	if (c == '%')
		return (ft_print_percent());
	if (c == 'x')
		return (ft_print_hex(va_arg(*ap, unsigned int), 'x'));
	if (c == 'X')
		return (ft_print_hex(va_arg(*ap, unsigned int), 'X'));
	return (-1);
}

static int	print_format(va_list *ap, const char **format)
{
	if (**format == '%')
	{
		if ((*format)[1] == '\0')
			return (-1);
		(*format)++;
		return (handle_arg(ap, **format));
	}
	return (write(STDOUT_FILENO, *format, 1));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		result;

	count = 0;
	result = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		result = print_format(&ap, &format);
		if (result < 0)
		{
			va_end(ap);
			return (-1);
		}
		count += result;
		format++;
	}
	va_end(ap);
	return (count);
}
