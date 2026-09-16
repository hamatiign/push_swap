#include "push_swap.h"

// static int	is_option(char *s)
// {
// 	if (ps_strcmp(s, "--simple") == 0)
// 		return (1);
// 	if (ps_strcmp(s, "--medium") == 0)
// 		return (1);
// 	if (ps_strcmp(s, "--complex") == 0)
// 		return (1);
// 	if (ps_strcmp(s, "--adaptive") == 0)
// 		return (1);
// 	return (0);
// }

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

int	parse_args(t_stack *a, t_context *ctx, int argc, char **argv)
{
	int		i;
	int		value;
	t_node	*node;

	i = 1;
	value = 0;
	if (!a || !ctx|| !argv)
		return (0);
	ctx->strategy = STRATEGY_ADAPTIVE;
	if (ps_strcmp(argv[i], "--bench") == 0)
	{
		ctx->bench = 1;
		i++;
	} else
		ctx->bench = 0;
	// やりました is_optionとparse_optionの処理がかぶってるからリファクタリングしたい
	if (i < argc)
	{
		if (parse_option(ctx, argv[i]))
			i++;
	}
	if (i >= argc)
		return (0);
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
	if (has_duplicate(a))
		return (0);
	return (1);
}
