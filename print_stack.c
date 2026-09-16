#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>
void print_stack(t_stack *stack) {
  t_node *current;

  if (!stack)
    return;
  current = stack->head;
  while (current) {
    ft_printf("%d_", current->value);
    current = current->next;
  }
  ft_printf("\n");
}

