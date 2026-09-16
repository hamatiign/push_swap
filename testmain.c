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



static char	*get_order(const t_context *ctx)
{
	t_strategy	algo;
	double		disorder;
	
	if (ctx->strategy == STRATEGY_ADAPTIVE)
	{
		disorder = ctx->disorder;
		if(disorder < SIMPLE_SORT_MAX_DISORDER)
			algo = STRATEGY_SIMPLE;
		else if(disorder < MEDIUM_SORT_MAX_DISORDER)
			algo = STRATEGY_MEDIUM;
		else
			algo = STRATEGY_COMPLEX;
	}
	else
		algo = ctx->strategy;
	if (algo == STRATEGY_SIMPLE)
		return ("O(n²)");
	else if (algo == STRATEGY_MEDIUM)
		return ("O(n√n)");
	else
		return ("O(nlogn)");
}

static int set_total_ops(t_stats *stats)
{
	return (stats->pa + stats->pb
			+ stats->sa + stats->sb + stats->ss 
			+ stats->ra + stats->rb + stats->rr
			+ stats->rra + stats->rrb + stats->rrr);
}

void print_stats(t_stats stats)
{
	ft_printf("total_ops:  %d\n", stats.total);
	ft_printf("sa:  %i  ", stats.sa);
	ft_printf("sb:  %i  ", stats.sb);
	ft_printf("ss:  %i  ", stats.ss);
	ft_printf("pa:  %i  ", stats.pa);
	ft_printf("pb:  %i\n", stats.pb);
	ft_printf("ra: %i ", stats.ra);
	ft_printf("rb:  %i ", stats.rb);
	ft_printf("rr:  %i ", stats.rr);
	ft_printf("rra:  %i  ", stats.rra);
	ft_printf("rrb:  %i  ", stats.rrb);
	ft_printf("rrr:  %i\n", stats.rrr);
}

static void print_bench(const t_context *ctx){
	ft_printf("disorder:  %.2f%%\n", ctx->disorder);
	ft_printf("strategy:  %s / %s\n", get_strategy_name(ctx->strategy), get_order(ctx));
	print_stats(ctx->stats);
  return ;
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
  //int values[] = {3, 7, 1, 5};
  t_context ctx;
  init_stats(&ctx.stats);

  stack_init(&a);
  stack_init(&b);
//  if (!init_stack_from_array(&a, values, 4))
//    return (1);
  ft_printf("\nparse_test\n");
  stack_clear(&a);
  stack_clear(&b);
  stack_init(&a);
  stack_init(&b);
//  (void)argc;
//	(void)argv;
  ft_printf("kaeriti = %d", parse_args(&a,&ctx, argc, argv));
  ft_printf("A: ");
  print_stack(&a);

	
	
	set_rank(&a);
	t_node	*node;
	node = (&a)->head;
	while (node)
	{
		ft_printf("v= %d, rank= %d\n", node->value, node->rank);
		node = node->next;
	}
	
	//////////////////////////////////////
	ctx.disorder = 0.345;
	ctx.strategy = STRATEGY_ADAPTIVE;
	 adaptive_sort(&a, &b, &ctx);
	 ctx.stats.total = set_total_ops(&ctx.stats);
	 print_ctx(&ctx);
//////////////////////////////////////////////

//  ft_printf("initial\n");
//  ft_printf("A: ");
//  print_stack(&a);
//  ft_printf("B: ");
//  print_stack(&b);

//  ft_printf("\nsa\n");
//  sa(&a, &ctx);
//  ft_printf("A: ");
//  print_stack(&a);
//  ft_printf("B: ");
//  print_stack(&b);

//  ft_printf("\npb\n");
//  pb(&a, &b, &ctx);
//  ft_printf("A: ");
//  print_stack(&a);
//  ft_printf("B: ");
//  print_stack(&b);

//  ft_printf("\npb\n");
//  pb(&a, &b, &ctx);
//  ft_printf("A: ");
//  print_stack(&a);
//  ft_printf("B: ");
//  print_stack(&b);

//  ft_printf("\npa\n");
//  pa(&a, &b, &ctx);
//  ft_printf("A: ");
//  print_stack(&a);
//  ft_printf("B: ");
//  print_stack(&b);

//  ft_printf("\nra\n");
//  ra(&a, &ctx);
//  ft_printf("A: ");
//  print_stack(&a);
//  ft_printf("B: ");
//  print_stack(&b);

//  ft_printf("\nrra\n");
//  rra(&a, &ctx);
//  ft_printf("A: ");
//  print_stack(&a);
//  ft_printf("B: ");
//  print_stack(&b);
  

  


//  ft_printf("init_stats");
//  init_stats(&ctx.stats);

//  set_rank(&a);

//  ft_printf("\nmedium_sort_test\n");
//  ft_printf("original_A: ");
//  print_stack(&a);
//  medium_sort(&a,&b, &ctx); 
//  ft_printf("sorted_A: ");
//  print_stack(&a);
//  ft_printf("B: ");
//  print_stack(&b);

//  ft_printf("\nctx_test\n");
//  print_ctx(&ctx);


  stack_clear(&a);
  stack_clear(&b);
  return (0);

}
