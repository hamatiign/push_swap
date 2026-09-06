#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>
void print_stack(t_stack *stack) {
  t_node *current;

  if (!stack)
    return;
  current = stack->head;
  while (current) {
    printf("%d_", current->value);
    current = current->next;
  }
  printf("\n");
}

// TODO ft_printfができ次第printfをそちらに変更
