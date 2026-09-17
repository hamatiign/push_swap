/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkajikaw <kkajikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 19:25:09 by kkajikaw          #+#    #+#             */
/*   Updated: 2026/09/17 19:48:25 by kkajikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	push_top(t_stack *dst, t_stack *src)
{
	if (!dst || !src || src->size == 0)
		return (0);
	stack_add_front(dst, stack_pop_front(src));
	return (1);
}

void	pa(t_stack *a, t_stack *b, t_context *ctx)
{
	if (push_top(a, b))
	{
		ctx->stats.pa++;
		write(STDOUT_FILENO, "pa\n", 3);
	}
}

void	pb(t_stack *a, t_stack *b, t_context *ctx)
{
	if (push_top(b, a))
	{
		ctx->stats.pb++;
		write(STDOUT_FILENO, "pb\n", 3);
	}
}
