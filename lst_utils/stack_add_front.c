
#include "../push_swap.h"

void stack_add_front(t_stack *stack, t_node *node) {
  if (!stack || !node)
    return;
  if (stack->head == NULL) {
    node->prev = NULL;
    node->next = NULL;
    stack->head = node;
    stack->tail = node;
    stack->size++;
    return;
  }
  stack->head->prev = node;
  node->next = stack->head;
  node->prev = NULL;
  stack->head = node;
  stack->size++;
}
