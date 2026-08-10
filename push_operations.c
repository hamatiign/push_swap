#include "push_swap.h"
static void push_top(t_stack *stack1, t_stack *stack2) {
  if (!stack2)
    return;
  if (stack2->size == 0)
    return;
  stack_add_back(stack1, stack2->head);
  stack2->head = stack2->head->next;
}
