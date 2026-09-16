#include "push_swap.h"
#include <stdio.h>



static void adaptive_sort(t_stack *a, t_stack *b, t_context *ctx){
	/*
		disorder　の計算はadaptive以外でも行う必要があるため、
		もっとでかいスコープでやっとく.
	*/

	const double	disorder = ctx->disorder;

	if(disorder < SIMPLE_SORT_MAX_DISORDER)
		simple_sort(a, b, ctx);
	else if(disorder < MEDIUM_SORT_MAX_DISORDER)
		medium_sort(a, b, ctx);
	else
		complex_sort(a, b, ctx);
}


//  ↓↓　デバッグ表示用のやつ.











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
  //int values[] = {3, 7, 1, 5};
  t_context ctx;
  init_stats(&ctx.stats);

  stack_init(&a);
  stack_init(&b);
//  if (!init_stack_from_array(&a, values, 4))
//    return (1);
  printf("\nparse_test\n");
  stack_clear(&a);
  stack_clear(&b);
  stack_init(&a);
  stack_init(&b);
//  (void)argc;
//	(void)argv;
  printf("kaeriti = %d", parse_args(&a,&ctx, argc, argv));
  printf("A: ");
  print_stack(&a);

	
	
	set_rank(&a);
	t_node	*node;
	node = (&a)->head;
	while (node)
	{
		printf("v= %d, rank= %d\n", node->value, node->rank);
		node = node->next;
	}
	
	//////////////////////////////////////
	ctx.disorder = 0.345;
	ctx.strategy = STRATEGY_ADAPTIVE;
	 adaptive_sort(&a, &b, &ctx);
	 ctx.stats.total = set_total_ops(&ctx.stats);
	 print_ctx(&ctx);
//////////////////////////////////////////////

//  printf("initial\n");
//  printf("A: ");
//  print_stack(&a);
//  printf("B: ");
//  print_stack(&b);

//  printf("\nsa\n");
//  sa(&a, &ctx);
//  printf("A: ");
//  print_stack(&a);
//  printf("B: ");
//  print_stack(&b);

//  printf("\npb\n");
//  pb(&a, &b, &ctx);
//  printf("A: ");
//  print_stack(&a);
//  printf("B: ");
//  print_stack(&b);

//  printf("\npb\n");
//  pb(&a, &b, &ctx);
//  printf("A: ");
//  print_stack(&a);
//  printf("B: ");
//  print_stack(&b);

//  printf("\npa\n");
//  pa(&a, &b, &ctx);
//  printf("A: ");
//  print_stack(&a);
//  printf("B: ");
//  print_stack(&b);

//  printf("\nra\n");
//  ra(&a, &ctx);
//  printf("A: ");
//  print_stack(&a);
//  printf("B: ");
//  print_stack(&b);

//  printf("\nrra\n");
//  rra(&a, &ctx);
//  printf("A: ");
//  print_stack(&a);
//  printf("B: ");
//  print_stack(&b);
  

  


//  printf("init_stats");
//  init_stats(&ctx.stats);

//  set_rank(&a);

//  printf("\nmedium_sort_test\n");
//  printf("original_A: ");
//  print_stack(&a);
//  medium_sort(&a,&b, &ctx); 
//  printf("sorted_A: ");
//  print_stack(&a);
//  printf("B: ");
//  print_stack(&b);

//  printf("\nctx_test\n");
//  print_ctx(&ctx);


  stack_clear(&a);
  stack_clear(&b);
  return (0);

}
