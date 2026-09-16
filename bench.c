#include "push_swap.h"

static char	*get_strategy_name(const t_strategy strategy)
{
	if (strategy == STRATEGY_SIMPLE)
		return ("Simple");
	if (strategy == STRATEGY_MEDIUM)
		return ("Medium");
	if (strategy == STRATEGY_COMPLEX)
		return ("Complex");
	return ("Adaptive");
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
	printf("total_ops:  %d\n", stats.total);
	printf("sa:  %i  ", stats.sa);
	printf("sb:  %i  ", stats.sb);
	printf("ss:  %i  ", stats.ss);
	printf("pa:  %i  ", stats.pa);
	printf("pb:  %i\n", stats.pb);
	printf("ra: %i ", stats.ra);
	printf("rb:  %i ", stats.rb);
	printf("rr:  %i ", stats.rr);
	printf("rra:  %i  ", stats.rra);
	printf("rrb:  %i  ", stats.rrb);
	printf("rrr:  %i\n", stats.rrr);
}

static void print_bench(const t_context *ctx){
	printf("disorder:  %.2f%%\n", ctx->disorder);
	printf("strategy:  %s / %s\n", get_strategy_name(ctx->strategy), get_order(ctx));
	print_stats(ctx->stats);
  return ;
}