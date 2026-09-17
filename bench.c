#include "push_swap.h"
#include <math.h>

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

static int set_total_ops(t_stats stats)
{
	return (stats.pa + stats.pb
			+ stats.sa + stats.sb + stats.ss 
			+ stats.ra + stats.rb + stats.rr
			+ stats.rra + stats.rrb + stats.rrr);
}

static void print_stats(t_stats stats)
{
	ft_printf_fd(STDERR_FILENO, "total_ops:  %d\n", stats.total);
	ft_printf_fd(STDERR_FILENO, "sa:  %i  ", stats.sa);
	ft_printf_fd(STDERR_FILENO, "sb:  %i  ", stats.sb);
	ft_printf_fd(STDERR_FILENO, "ss:  %i  ", stats.ss);
	ft_printf_fd(STDERR_FILENO, "pa:  %i  ", stats.pa);
	ft_printf_fd(STDERR_FILENO, "pb:  %i\n", stats.pb);
	ft_printf_fd(STDERR_FILENO, "ra: %i ", stats.ra);
	ft_printf_fd(STDERR_FILENO, "rb:  %i ", stats.rb);
	ft_printf_fd(STDERR_FILENO, "rr:  %i ", stats.rr);
	ft_printf_fd(STDERR_FILENO, "rra:  %i  ", stats.rra);
	ft_printf_fd(STDERR_FILENO, "rrb:  %i  ", stats.rrb);
	ft_printf_fd(STDERR_FILENO, "rrr:  %i\n", stats.rrr);
}

static char	*get_disorder_str(double disorder)
{
	int	disorder_intpart;
	int	disorder_minpart;

	disorder_intpart = ceil(disorder);
	disorder_minpart = 
}

void print_bench(t_context *ctx){
	ctx->stats.total = set_total_ops(ctx->stats);
	ft_printf_fd(STDERR_FILENO, "disorder:  %s%\n", get_disorder_str(ctx->disorder));
	ft_printf_fd(STDERR_FILENO, "strategy:  %s / %s\n", get_strategy_name(ctx->strategy));
	print_stats(ctx->stats);
  return ;
}