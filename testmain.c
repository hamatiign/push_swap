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

static char	*get_strategy_name(t_strategy strategy)
{
	if (strategy == STRATEGY_SIMPLE)
		return ("simple");
	if (strategy == STRATEGY_MEDIUM)
		return ("medium");
	if (strategy == STRATEGY_COMPLEX)
		return ("complex");
	return ("adaptive");
}

static int print_ctx(t_context *ctx){
  printf("disorder: %f\n", ctx->disorder);
  printf("pa: %i\n", ctx->stats.pa);
  printf("pb: %i\n", ctx->stats.pb);
  printf("sa: %i\n", ctx->stats.sa);
  printf("sb: %i\n", ctx->stats.sb);
  printf("ss: %i\n", ctx->stats.ss);
  printf("ra: %i\n", ctx->stats.ra);
  printf("rb: %i\n", ctx->stats.rb);
  printf("rra: %i\n", ctx->stats.rra);
  printf("rrb: %i\n", ctx->stats.rrb);
  printf("rrr: %i\n", ctx->stats.rrr);
  printf("strategy: %s\n", get_strategy_name(ctx->strategy));
  return (0);
}

void	init_stats(t_stats *stats)
{
	stats->total = 0;
	stats->sa = 0;
	stats->sb = 0;
	stats->ss = 0;
	stats->pa = 0;
	stats->pb = 0;
	stats->ra = 0;
	stats->rb = 0;
	stats->rr = 0;
	stats->rra = 0;
	stats->rrb = 0;
	stats->rrr = 0;
}

int main(int argc, char **argv) {
  t_stack a;
  t_stack b;
  int values[] = {3, 7, 1, 5};
  t_context ctx;
  init_stats(&ctx.stats);

  stack_init(&a);
  stack_init(&b);
  if (!init_stack_from_array(&a, values, 4))
    return (1);

	
	(void)argc;
	(void)argv;
	set_rank(&a);
	t_node	*node;
	node = (&a)->head;
	while (node)
	{
		printf("v= %d, rank= %d\n", node->value, node->rank);
		node = node->next;
	}
	
	// complex_sort(&a, &b);

  printf("initial\n");
  printf("A: ");
  print_stack(&a);
  printf("B: ");
  print_stack(&b);

  printf("\nsa\n");
  sa(&a, &ctx);
  printf("A: ");
  print_stack(&a);
  printf("B: ");
  print_stack(&b);

  printf("\npb\n");
  pb(&a, &b, &ctx);
  printf("A: ");
  print_stack(&a);
  printf("B: ");
  print_stack(&b);

  printf("\npb\n");
  pb(&a, &b, &ctx);
  printf("A: ");
  print_stack(&a);
  printf("B: ");
  print_stack(&b);

  printf("\npa\n");
  pa(&a, &b, &ctx);
  printf("A: ");
  print_stack(&a);
  printf("B: ");
  print_stack(&b);

  printf("\nra\n");
  ra(&a, &ctx);
  printf("A: ");
  print_stack(&a);
  printf("B: ");
  print_stack(&b);

  printf("\nrra\n");
  rra(&a, &ctx);
  printf("A: ");
  print_stack(&a);
  printf("B: ");
  print_stack(&b);
  
  printf("\nparse_test\n");
  stack_clear(&a);
  stack_clear(&b);
  stack_init(&a);
  stack_init(&b);
  parse_args(&a,&ctx, argc, argv);
  printf("A: ");
  print_stack(&a);
  


  printf("init_stats");
  init_stats(&ctx.stats);

  set_rank(&a);

  printf("\nmedium_sort_test\n");
  printf("original_A: ");
  print_stack(&a);
  medium_sort(&a,&b, &ctx); 
  printf("sorted_A: ");
  print_stack(&a);
  printf("B: ");
  print_stack(&b);

  printf("\nctx_test\n");
  print_ctx(&ctx);


  stack_clear(&a);
  stack_clear(&b);
  return (0);

}
