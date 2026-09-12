#include "push_swap.h"


static void adaptive_sort(t_stack *a, t_stack *b){
    double disorder;

  disorder = compute_disorder(a);
  if(disorder < 0.2) simple_sort(a, b);
  else if(disorder < 0.5) medium_sort(a, b);
  else  complex_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
t_context ctx;

	if (argc == 1)
		return (0);
	stack_init(&a);
	stack_init(&b);
	if (!parse_args(&a, &ctx.strategy, argc, argv))
	{
		stack_clear(&a);
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	// ーーーテスト用コードーーーーー
	stack_add_back(&a, node_new(5));
	stack_add_back(&a, node_new(1));
	stack_add_back(&a, node_new(7));
	stack_add_back(&a, node_new(9));
	stack_add_back(&b, node_new(3));
	stack_add_back(&b, node_new(5));
	// ーーーテスト用コードーーーーー
	/* argvを検証 */
	/* argvからAを作る */
	/* disorder計算 */
	/* ソート */
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
