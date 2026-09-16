/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_putstr_stderr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkajikaw <kkajikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 16:49:03 by kkajikaw          #+#    #+#             */
/*   Updated: 2026/09/16 18:48:49 by kkajikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"
//bench 表示用にfdをstrerr にするprintをつくる

size_t static ps_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void ps_putstr_stderr(char *s)
{
	write(STDERR_FILENO, s, ps_strlen(s));
}