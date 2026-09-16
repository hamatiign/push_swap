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

int set_total_ops(t_stats *stats)
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

void print_bench(const t_context *ctx){
	ft_printf("disorder:  %.2f%%\n", ctx->disorder);
	ft_printf("strategy:  %s / %s\n", get_strategy_name(ctx->strategy));
	print_stats(ctx->stats);
  return ;
}