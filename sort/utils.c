#include "../push_swap.h"

t_node *get_min_node(t_stack *stack) {
  t_node *node;
  t_node *ret_node;
  if (!stack || !stack->head)
    return (NULL);

  node = stack->head;
  ret_node = stack->head;
  while (node) {
    if (node->value < ret_node->value)
      ret_node = node;
    node = node->next;
  }
  return (ret_node);
}

int get_node_index(t_stack *stack, t_node *target) {
  t_node *node;
  int index;

  if (!stack || !target)
    return (-1);
  node = stack->head;
  index = 0;
  while (node) {
    if (node == target)
      return (index);
    node = node->next;
    index++;
  }
  return (-1);
}

int is_sorted(t_stack *stack) {
  t_node *node;
  if (!stack || stack->size < 2)
    return (1);

  node = stack->head;
  while (node->next) {
    if (node->value > node->next->value)
      return (0);
    node = node->next;
  }
  return (1);
}
