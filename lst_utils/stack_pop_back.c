
#include "../push_swap.h"

t_node *stack_pop_back(t_stack *stack) {
  t_node *ret_node;

  if (!stack || stack->size == 0)
    return (NULL);
  ret_node = stack->tail;
  stack->tail = ret_node->prev;
  if (stack->tail)
    stack->tail->next = NULL;
  else
    stack->head = NULL;
  ret_node->next = NULL;
  ret_node->prev = NULL;
  stack->size--;
  return (ret_node);
}
