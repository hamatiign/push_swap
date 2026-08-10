#include "push_swap.h"
void stack_clear(t_stack *stack) {
  t_node *current;
  t_node *next;

  if (!stack)
    return;
  current = stack->head;
  while (current) {
    next = current->next;
    free(current);
    current = next;
  }
  stack->head = NULL;
  stack->tail = NULL;
  stack->size = 0;
}
