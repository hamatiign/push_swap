#include "push_swap.h"

void stack_add_back(t_stack *stack, t_node *node) {
  if (!stack || !node)
    return;
  if (stack->head == NULL) {
    stack->head = node;
    stack->tail = node;
    stack->size++;
    return;
  }
  stack->tail->next = node;
  stack->size++;
  node->prev = stack->tail;
  stack->tail = node;
}
