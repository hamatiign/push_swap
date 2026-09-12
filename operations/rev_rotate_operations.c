/*
	ra, rb -> 先頭が末尾要素に
	rr -> ra と rb の同時実行
	rra, rrb -> 最後の要素が最初の要素に
	rrr -> 同時に実行
*/

#include "../push_swap.h"

static void tail_to_head(t_stack *stack) {
	t_node	*last;

	last = stack->tail;
	stack->tail = last->prev;
	stack->tail->next = NULL;
	stack->head->prev = last;
	last->next = stack->head;
	stack->head = last;
	last->prev = NULL;
}

void rra(t_stack *a, t_context *ctx) {
	if (!a || a->size < 2)
		return;
	tail_to_head(a);
  ctx->stats.rra++;
	write(STDOUT_FILENO, "rra\n", 4);
}

void rrb(t_stack *b, t_context *ctx) {
	if (!b || b->size < 2)
		return;
	tail_to_head(b);
  ctx->stats.rrb++;
	write(STDOUT_FILENO, "rrb\n", 4);
}

void rrr(t_stack *a, t_stack *b, t_context *ctx) {
  if (!a || a->size < 2)
    return;
  if (!b || b->size < 2)
    return;
  tail_to_head(a);
  tail_to_head(b);
  ctx->stats.rrr++;
  write(STDOUT_FILENO, "rrr\n", 4);
}
