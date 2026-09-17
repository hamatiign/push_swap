/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkajikaw <kkajikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 19:23:57 by kkajikaw          #+#    #+#             */
/*   Updated: 2026/09/17 19:23:58 by kkajikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap_top(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	first = stack->head;
	second = first->next;
	first->next = second->next;
	if (first->next)
		first->next->prev = first;
	else
		stack->tail = first;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	stack->head = second;
}

void	sa(t_stack *a, t_context *ctx)
{
	if (!a || a->size < 2)
		return ;
	swap_top(a);
	ctx->stats.sa++;
	write(STDOUT_FILENO, "sa\n", 3);
}

void	sb(t_stack *b, t_context *ctx)
{
	if (!b || b->size < 2)
		return ;
	swap_top(b);
	ctx->stats.sb++;
	write(STDOUT_FILENO, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b, t_context *ctx)
{
	if ((!a || a->size < 2) && (!b || b->size < 2))
		return ;
	if (a && a->size >= 2)
		swap_top(a);
	if (b && b->size >= 2)
		swap_top(b);
	ctx->stats.ss++;
	write(STDOUT_FILENO, "ss\n", 3);
}
