#include "push_swap.h"

t_node *stack_pop_front(t_stack *stack) {
  t_node *ret_node;

  if (!stack || stack->size == 0)
    return (NULL);
  ret_node = stack->head;
  stack->head = ret_node->next;
  if (stack->head)
    stack->head->prev = NULL;
  else
    stack->tail = NULL;
  ret_node->next = NULL;
  ret_node->prev = NULL;
  stack->size--;
  return (ret_node);
}
