#include "push_swap.h"

double compute_disorder(t_stack *a) {
  int mistakes;
  int total_pairs;

  t_node *current;
  t_node *compare;
  if (!a || a->size < 2)
    return (0.0);

  mistakes = 0;
  total_pairs = 0;
  current = a->head;
  while (current) {
    compare = current->next;
    while (compare) {
      if (current->value > compare->value)
        mistakes++;
      total_pairs++;
      compare = compare->next;
    }
    current = current->next;
  }

  return ((double)mistakes / (double)total_pairs);
}
