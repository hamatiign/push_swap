#include "push_swap.h"
#include <stdio.h>

static int init_stack_from_array(t_stack *stack, int *arr, int size) {
  t_node *node;
  int i;

  i = 0;
  while (i < size) {
    node = node_new(arr[i]);
    if (!node) {
      stack_clear(stack);
      return (0);
    }
    stack_add_back(stack, node);
    i++;
  }
  return (1);
}

int main(void) {
  t_stack a;
  t_stack b;
  int values[] = {3, 7, 1, 5};

  stack_init(&a);
  stack_init(&b);
  if (!init_stack_from_array(&a, values, 4))
    return (1);

  printf("initial\n");
  printf("A: ");
  print_stack(&a);
  printf("B: ");
  print_stack(&b);

  printf("\nsa\n");
  sa(&a);
  printf("A: ");
  print_stack(&a);
  printf("B: ");
  print_stack(&b);

  printf("\npb\n");
  pb(&a, &b);
  printf("A: ");
  print_stack(&a);
  printf("B: ");
  print_stack(&b);

  printf("\npb\n");
  pb(&a, &b);
  printf("A: ");
  print_stack(&a);
  printf("B: ");
  print_stack(&b);

  printf("\npa\n");
  pa(&a, &b);
  printf("A: ");
  print_stack(&a);
  printf("B: ");
  print_stack(&b);

  stack_clear(&a);
  stack_clear(&b);
  return (0);
}
