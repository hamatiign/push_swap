#include "../push_swap.h"
#include <math.h>

void medium_sort(t_stack *a, t_stack *b) {
  const int chunk_size = ceil(sqrt(a->size));
  int chunk_number = 0;
  int size;
  while (a->size > 0) {
    size = a->size;
    while (size-- > 0) {
      if (a->head->rank >= chunk_size * chunk_number &&
          a->head->rank < chunk_size * (chunk_number + 1)) {
        pb(a, b);
      } else
        ra(a);
    }
    chunk_number++;
  }

  int max_node_index;
  while (b->head) {
    max_node_index = get_node_index(b, get_max_node(b));
    if (max_node_index <= b->size / 2) {
      while (max_node_index-- > 0)
        rb(b);
    } else {
      while (max_node_index++ < b->size)
        rrb(b);
    }
    pa(a, b);
  }
}
