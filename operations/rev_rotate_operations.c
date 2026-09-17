/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkajikaw <kkajikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 19:24:11 by kkajikaw          #+#    #+#             */
/*   Updated: 2026/09/17 19:24:59 by kkajikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	tail_to_head(t_stack *stack)
{
	t_node	*last;

	last = stack->tail;
	stack->tail = last->prev;
	stack->tail->next = NULL;
	stack->head->prev = last;
	last->next = stack->head;
	stack->head = last;
	last->prev = NULL;
}

void	rra(t_stack *a, t_context *ctx)
{
	if (!a || a->size < 2)
		return ;
	tail_to_head(a);
	ctx->stats.rra++;
	write(STDOUT_FILENO, "rra\n", 4);
}

void	rrb(t_stack *b, t_context *ctx)
{
	if (!b || b->size < 2)
		return ;
	tail_to_head(b);
	ctx->stats.rrb++;
	write(STDOUT_FILENO, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b, t_context *ctx)
{
	if (!a || a->size < 2)
		return ;
	if (!b || b->size < 2)
		return ;
	tail_to_head(a);
	tail_to_head(b);
	ctx->stats.rrr++;
	write(STDOUT_FILENO, "rrr\n", 4);
}
