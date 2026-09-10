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
	last->prev = last;
}

void rra(t_stack *a) {
	if (!a || a->size < 2)
		return;
	tail_to_head(a);
	write(STDOUT_FILENO, "rra\n", 3);
}

void rrb(t_stack *b) {
	if (!b || b->size < 2)
		return;
	tail_to_head(b);
	write(STDOUT_FILENO, "rrb\n", 3);
}

void rrr(t_stack *a, t_stack *b) {
  if (!a || a->size < 2)
    return;
  if (!b || b->size < 2)
    return;
  tail_to_head(a);
  tail_to_head(b);
  write(STDOUT_FILENO, "rrr\n", 3);
}