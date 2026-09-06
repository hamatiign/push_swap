#include "push_swap.h"
#include <unistd.h>

static void swap_top(t_stack *stack) {
  t_node *first;
  t_node *second;

  first = stack->head;
  second = first->next;
  first->next = second->next;
  if (first->next)
    first->next->prev = first;
  else
    stack->tail = first;
  first->prev = second;
  second->next = first;
  second->prev = NULL;
  stack->head = second;
}

void sa(t_stack *a) {
  if (!a || a->size < 2)
    return;
  swap_top(a);
  write(STDOUT_FILENO, "sa\n", 3);
}

void sb(t_stack *b) {
  if (!b || b->size < 2)
    return;
  swap_top(b);
  write(STDOUT_FILENO, "sb\n", 3);
}

void ss(t_stack *a, t_stack *b) {
  if (!a || a->size < 2)
    return;
  if (!b || b->size < 2)
    return;
  swap_top(a);
  swap_top(b);
  write(STDOUT_FILENO, "ss\n", 3);
}
