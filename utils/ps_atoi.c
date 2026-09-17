/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkajikaw <kkajikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 19:03:57 by kkajikaw          #+#    #+#             */
/*   Updated: 2026/09/17 20:17:47 by kkajikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>

static int	ps_atoi_core(const char *s,
	long long *result, const int sign, int *value)
{
	while (*s)
	{
		if (!ps_isdigit(*s))
			return (0);
		*result = *result * 10 + (*s - '0');
		if (sign == 1 && *result > (INT_MAX))
			return (0);
		if (sign == -1 && - *result < (INT_MIN))
			return (0);
		s++;
	}
	*value = (int)(*result * sign);
	return (1);
}

int	ps_atoi(const char *s, int *value)
{
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	if (!s || *s == '\0')
		return (0);
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	if (*s == '\0')
		return (0);
	return (ps_atoi_core(s, &result, sign, value));
}
