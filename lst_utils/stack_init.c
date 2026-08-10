#include "push_swap.h"

void stack_init(t_stack *stack) {
  if (!stack)
    return;
  stack->head = NULL;
  stack->tail = NULL;
  stack->size = 0;
}
