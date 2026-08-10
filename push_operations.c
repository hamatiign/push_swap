#include "push_swap.h"
#include <unistd.h>

static int push_top(t_stack *dst, t_stack *src) {
  if (!dst || !src || src->size == 0)
    return (0);
  stack_add_front(dst, stack_pop_front(src));
  return (1);
}

void pa(t_stack *a, t_stack *b) {

  if (push_top(a, b))
    write(STDOUT_FILENO, "pa\n", 3);
}

void pb(t_stack *a, t_stack *b) {
  if (push_top(b, a))
    write(STDOUT_FILENO, "pb\n", 3);
}
