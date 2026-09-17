/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkajikaw <kkajikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 20:59:46 by kkajikaw          #+#    #+#             */
/*   Updated: 2026/09/17 21:02:26 by kkajikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(t_stack *a, t_stack *b, t_context *ctx);
static void	sort_mini(t_stack *a, t_context *ctx);
static void	sort_three(t_stack *a, t_context *ctx);

static void	sort(t_stack *a, t_stack *b, t_context *ctx)
{
	t_strategy	strategy;
	double		disorder;

	strategy = ctx->strategy;
	disorder = ctx->disorder;
	if (strategy == STRATEGY_SIMPLE)
		simple_sort(a, b, ctx);
	else if (strategy == STRATEGY_MEDIUM)
		medium_sort(a, b, ctx);
	else if (strategy == STRATEGY_COMPLEX)
		complex_sort(a, b, ctx);
	else
	{
		if (disorder < SIMPLE_SORT_MAX_DISORDER)
			simple_sort(a, b, ctx);
		else if (disorder < MEDIUM_SORT_MAX_DISORDER)
			medium_sort(a, b, ctx);
		else
			complex_sort(a, b, ctx);
	}
}

static void	sort_mini(t_stack *a, t_context *ctx)
{
	if (a->size == 2)
	{
		if (a->head->value > a->tail->value)
			sa(a, ctx);
	}
	else
		sort_three(a, ctx);
	return ;
}

static void	sort_three(t_stack *a, t_context *ctx)
{
	int	first;
	int	second;
	int	third;

	first = a->head->value;
	second = a->head->next->value;
	third = a->tail->value;
	if (first > second)
	{
		if (first > third)
			ra(a, ctx);
	}
	else
	{
		if (second > third)
			rra(a, ctx);
	}
	if (a->head->value > a->head->next->value)
		sa(a, ctx);
}

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_context	ctx;

	if (argc == 1)
		return (0);
	stack_init(&a);
	if (!parse_args(&a, &ctx, argc, argv))
	{
		stack_clear(&a);
		ft_printf_fd(STDERR_FILENO, "Error\n");
		return (1);
	}
	set_rank(&a);
	stack_init(&b);
	stats_init(&(ctx.stats));
	ctx.disorder = compute_disorder(&a);
	if (a.size <= 3)
		sort_mini(&a, &ctx);
	else
		sort(&a, &b, &ctx);
	if (ctx.bench)
		print_bench(&ctx);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
