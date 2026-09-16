#include "push_swap.h"

//static int init_stack_from_array(t_stack *stack, int *arr, int size) {
//  t_node *node;
//  int i;

//  i = 0;
//  while (i < size) {
//    node = node_new(arr[i]);
//    if (!node) {
//      stack_clear(stack);
//      return (0);
//    }
//    stack_add_back(stack, node);
//    i++;
//  }
//  return (1);
//}

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
		if(disorder < SIMPLE_SORT_MAX_DISORDER)
			simple_sort(a, b, ctx);
		else if(disorder < MEDIUM_SORT_MAX_DISORDER)
			medium_sort(a, b, ctx);
		else
			complex_sort(a, b, ctx);
	}
}

/*first > second , second > third
3 2 1

first > second, second < third
	first > third
	3 1 2
	first < third
	2 1 3

first < second , second > third
	1 3 2

	2 3 1
	*/

static void	sort_mini(t_stack *a, t_stack *b, t_context *ctx)
{
	if (a->size == 2)
	{
		if (a->head->value > a->tail->value)
			sa(a, ctx);
	} else{
		sort_three(a, b, ctx);
	}
	return ;
}

static void sort_three(t_stack *a, t_stack *b, t_context *ctx)
{
	int	first;
	int	second;
	int third;

	first = a->head->value;
	second = a->head->next->value;
	third = a->tail->value;
	if (first > second)
	{
		if (second > third)
		{
			ra(a, ctx);
			sa(a, ctx);
		} else {
			if (first > third)
				ra(a, ctx);
			else
				sa(a, ctx);
		} else {
			if (second )
		}
	} else 
	{
		if (second > third)

	}
}

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_context ctx;

	if (argc == 1)
		return (0);
	stack_init(&a);

	/* parse_args に--bench処理を追加する
		＊argv[1]が--benchならargv[2]にSTRATEGY判定をする
		みたいなことを多分かけた気がします
		*/
	if (!parse_args(&a, &ctx.strategy, argc, argv))
	{
		stack_clear(&a);
		ps_putstr_stderr("Error\n");
		return (1);
	}

	stack_init(&b);
	init_stats(&ctx.stats);
	//必要量のnode を含めたmallocができたかどうか たぶんparse_argsの中でやってる.
	//if (!init_stack_from_array(&a, values, **ここなに**));
	//	return (1);
	ctx.disorder = compute_disorder(&a);
	/* ソート */
	// strategy に応じて どのソートにするか決める処理*

	// 2 toka 3 toka no  sort dousiyou
	if (a.size <= 3)
		sort_mini(&a, &b, &ctx);

	sort(&a, &b, &ctx);

	// bench表示 
	if (ctx.bench)
	{

	}



	stack_clear(&a);
	stack_clear(&b);
	return (0);
}

	// ーーーテスト用コードーーーーー
	//stack_add_back(&a, node_new(5));
	//stack_add_back(&a, node_new(1));
	//stack_add_back(&a, node_new(7));
	//stack_add_back(&a, node_new(9));
	//stack_add_back(&b, node_new(3));
	//stack_add_back(&b, node_new(5));
	// ーーーテスト用コードーーーーー