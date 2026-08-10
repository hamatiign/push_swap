#include "../push_swap.h"

t_node *node_new(int value) {
  t_node *node;

  node = (t_node *)malloc(sizeof(t_node));
  if (node == NULL)
    return (NULL);
  node->value = value;
  node->next = NULL;
  node->prev = NULL;
  return (node);
}
