/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkajikaw <kkajikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 20:30:18 by kkajikaw          #+#    #+#             */
/*   Updated: 2026/09/17 20:58:47 by kkajikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_option(t_context *ctx, char *s)
{
	if (ps_strcmp(s, "--simple") == 0)
		ctx->strategy = STRATEGY_SIMPLE;
	else if (ps_strcmp(s, "--medium") == 0)
		ctx->strategy = STRATEGY_MEDIUM;
	else if (ps_strcmp(s, "--complex") == 0)
		ctx->strategy = STRATEGY_COMPLEX;
	else if (ps_strcmp(s, "--adaptive") == 0)
		ctx->strategy = STRATEGY_ADAPTIVE;
	else
		return (0);
	return (1);
}

static int	has_duplicate(t_stack *a)
{
	t_node	*current;
	t_node	*compare;

	current = a->head;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			if (current->value == compare->value)
				return (1);
			compare = compare->next;
		}
		current = current->next;
	}
	return (0);
}

static int	parse_options(t_context *ctx, int argc, char **argv, int *i)
{
	int	strategy_set;

	strategy_set = 0;
	while (*i < argc)
	{
		if (ps_strcmp(argv[*i], "--bench") == 0)
		{
			if (ctx->bench)
				return (0);
			ctx->bench = 1;
		}
		else if (parse_option(ctx, argv[*i]))
		{
			if (strategy_set)
				return (0);
			strategy_set = 1;
		}
		else
			break ;
		(*i)++;
	}
	return (1);
}

static int	fill_stack(t_stack *a, char **argv, int i, const int argc)
{
	int		value;
	t_node	*node;

	while (i < argc)
	{
		if (!ps_atoi(argv[i], &value))
			return (0);
		node = node_new(value);
		if (node == NULL)
			return (0);
		stack_add_back(a, node);
		i++;
	}
	return (1);
}

int	parse_args(t_stack *a, t_context *ctx, int argc, char **argv)
{
	int	i;

	i = 1;
	if (!a || !ctx || !argv)
		return (0);
	ctx->strategy = STRATEGY_ADAPTIVE;
	ctx->bench = 0;
	if (!parse_options(ctx, argc, argv, &i))
		return (0);
	if (i >= argc || !fill_stack(a, argv, i, argc))
		return (0);
	return (!has_duplicate(a));
}
