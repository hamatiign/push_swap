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

int main(int argc, char **argv) {
  t_stack a;
  t_stack b;
  int values[] = {3, 7, 1, 5};
  t_strategy strategy;

  stack_init(&a);
  stack_init(&b);
  if (!init_stack_from_array(&a, values, 4))
    return (1);

	
	(void)argc;
	(void)argv;
	(void)strategy;
	set_rank(&a);
	t_node	*node;
	node = (&a)->head;
	while (node)
	{
		printf("v= %d, rank= %d\n", node->value, node->rank);
		node = node->next;
	}
	
	complex_sort(&a, &b);

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

  printf("\nra\n");
  ra(&a);
  printf("A: ");
  print_stack(&a);
  printf("B: ");
  print_stack(&b);

  printf("\nrra\n");
  rra(&a);
  printf("A: ");
  print_stack(&a);
  printf("B: ");
  print_stack(&b);
  
  printf("\nparse_test\n");
  stack_clear(&a);
  stack_init(&a);
  parse_args(&a, &strategy, argc, argv);
  printf("A: ");
  print_stack(&a);
  printf("strategy_index: %d\n", strategy);
  

  stack_clear(&a);
  stack_clear(&b);
  return (0);


}
