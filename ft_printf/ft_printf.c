/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkajikaw <kkajikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 11:32:03 by nkato             #+#    #+#             */
/*   Updated: 2026/09/16 21:33:54 by kkajikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	handle_arg(int fd, va_list *ap, char c)
{
	if (c == 'd' || c == 'i')
		return (ft_print_int(fd, va_arg(*ap, int)));
	if (c == 'u')
		return (ft_print_uint(fd, va_arg(*ap, unsigned int)));
	if (c == 'c')
		return (ft_print_char(fd, va_arg(*ap, int)));
	if (c == 's')
		return (ft_print_string(fd, va_arg(*ap, char *)));
	if (c == 'p')
		return (ft_print_ptr(fd, va_arg(*ap, void *)));
	if (c == '%')
		return (ft_print_percent(fd));
	if (c == 'x')
		return (ft_print_hex(fd, va_arg(*ap, unsigned int), 'x'));
	if (c == 'X')
		return (ft_print_hex(fd, va_arg(*ap, unsigned int), 'X'));
	return (-1);
}

static int	print_format(int fd, va_list *ap, const char **format)
{
	if (**format == '%')
	{
		if ((*format)[1] == '\0')
			return (-1);
		(*format)++;
		return (handle_arg(fd, ap, **format));
	}
	return (write(fd, *format, 1));
}

int	ft_printf_fd(int fd, const char *format, ...)
{
	va_list	ap;
	int		count;
	int		result;

	count = 0;
	result = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		result = print_format(fd, &ap, &format);
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
