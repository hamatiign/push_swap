/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkajikaw <kkajikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 20:37:29 by nkato             #+#    #+#             */
/*   Updated: 2026/09/16 21:22:25 by kkajikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdint.h>
# include <unistd.h>

int	ft_printf(int fd, const char *format, ...);
int	ft_print_char(int fd, int c);
int	ft_print_string(int fd, char *str);
int	ft_print_ptr(int fd, void *ptr);
int	ft_print_int(int fd, int n);
int	ft_print_uint(int fd, unsigned int n);
int	ft_print_hex(int fd, unsigned int n, char specifier);
int	ft_print_percent(int fd);
int	ft_putnbr_base(int fd, uintptr_t nbr, char *base);

#endif
