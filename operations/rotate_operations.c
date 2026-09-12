/*
	ra, rb -> 先頭が末尾要素に
	rr -> ra と rb の同時実行
	rra, rrb -> 最後の要素が最初の要素に
	rrr -> 同時に実行
*/

#include "../push_swap.h"

static void head_to_tail(t_stack *stack) {
	t_node	*first;

	first = stack->head;
	stack->head = first->next;
	stack->head->prev = NULL;
	stack->tail->next = first;
	first->prev = stack->tail;
	stack->tail = first;
	first->next = NULL;
}

void ra(t_stack *a, t_context *ctx) {
	if (!a || a->size < 2)
		return;
	head_to_tail(a);
  ctx->stats.ra++;
	write(STDOUT_FILENO, "ra\n", 3);
}

void rb(t_stack *b, t_context *ctx) {
	if (!b || b->size < 2)
		return;
	head_to_tail(b);
  ctx->stats.rb++;
	write(STDOUT_FILENO, "rb\n", 3);
}

void rr(t_stack *a, t_stack *b, t_context *ctx) {
  if (!a || a->size < 2)
    return;
  if (!b || b->size < 2)
    return;
  head_to_tail(a);
  head_to_tail(b);
  ctx->stats.rr++;
  write(STDOUT_FILENO, "rr\n", 3);
}
