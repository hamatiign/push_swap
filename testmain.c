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
  ft_printf_fd(STDOUT_FILENO, "\nparse_test\n");
  stack_clear(&a);
  stack_clear(&b);
  stack_init(&a);
  stack_init(&b);
//  (void)argc;
//	(void)argv;
  ft_printf_fd(STDOUT_FILENO, "kaeriti = %d", parse_args(&a,&ctx, argc, argv));
  ft_printf_fd(STDOUT_FILENO, "A: ");
  print_stack(&a);

	
	
	set_rank(&a);
	t_node	*node;
	node = (&a)->head;
	while (node)
	{
		ft_printf_fd(STDOUT_FILENO, "v= %d, rank= %d\n", node->value, node->rank);
		node = node->next;
	}
	
	//////////////////////////////////////
	ctx.disorder = 0.345;
	ctx.strategy = STRATEGY_ADAPTIVE;
	 adaptive_sort(&a, &b, &ctx);
	 ctx.stats.total = set_total_ops(&ctx.stats);
	 print_bench(&ctx);
//////////////////////////////////////////////


//  ft_printf_fd(STDOUT_FILENO, "initial\n");
//  ft_printf_fd(STDOUT_FILENO, "A: ");
//  print_stack(&a);
//  ft_printf_fd(STDOUT_FILENO, "B: ");
//  print_stack(&b);

//  ft_printf_fd(STDOUT_FILENO, "\nsa\n");
//  sa(&a, &ctx);
//  ft_printf_fd(STDOUT_FILENO, "A: ");
//  print_stack(&a);
//  ft_printf_fd(STDOUT_FILENO, "B: ");
//  print_stack(&b);

//  ft_printf_fd(STDOUT_FILENO, "\npb\n");
//  pb(&a, &b, &ctx);
//  ft_printf_fd(STDOUT_FILENO, "A: ");
//  print_stack(&a);
//  ft_printf_fd(STDOUT_FILENO, "B: ");
//  print_stack(&b);

//  ft_printf_fd(STDOUT_FILENO, "\npb\n");
//  pb(&a, &b, &ctx);
//  ft_printf_fd(STDOUT_FILENO, "A: ");
//  print_stack(&a);
//  ft_printf_fd(STDOUT_FILENO, "B: ");
//  print_stack(&b);

//  ft_printf_fd(STDOUT_FILENO, "\npa\n");
//  pa(&a, &b, &ctx);
//  ft_printf_fd(STDOUT_FILENO, "A: ");
//  print_stack(&a);
//  ft_printf_fd(STDOUT_FILENO, "B: ");
//  print_stack(&b);

//  ft_printf_fd(STDOUT_FILENO, "\nra\n");
//  ra(&a, &ctx);
//  ft_printf_fd(STDOUT_FILENO, "A: ");
//  print_stack(&a);
//  ft_printf_fd(STDOUT_FILENO, "B: ");
//  print_stack(&b);

//  ft_printf_fd(STDOUT_FILENO, "\nrra\n");
//  rra(&a, &ctx);
//  ft_printf_fd(STDOUT_FILENO, "A: ");
//  print_stack(&a);
//  ft_printf_fd(STDOUT_FILENO, "B: ");
//  print_stack(&b);
  

  


//  ft_printf_fd(STDOUT_FILENO, "init_stats");
//  init_stats(&ctx.stats);

//  set_rank(&a);

//  ft_printf_fd(STDOUT_FILENO, "\nmedium_sort_test\n");
//  ft_printf_fd(STDOUT_FILENO, "original_A: ");
//  print_stack(&a);
//  medium_sort(&a,&b, &ctx); 
//  ft_printf_fd(STDOUT_FILENO, "sorted_A: ");
//  print_stack(&a);
//  ft_printf_fd(STDOUT_FILENO, "B: ");
//  print_stack(&b);

//  ft_printf_fd(STDOUT_FILENO, "\nctx_test\n");
//  print_ctx(&ctx);


  stack_clear(&a);
  stack_clear(&b);
  return (0);

}
