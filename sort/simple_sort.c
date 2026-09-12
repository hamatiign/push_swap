#include "../push_swap.h"

void simple_sort(t_stack *a, t_stack *b, t_context *ctx)
{
	const int	stack_size = a->size;
	int			i;
	int			a_size;
	int			a_min_index;

	i = 0;
	while (i++ < stack_size - 1)
	{
		if (is_sorted(a))
			break ;
		a_min_index = get_node_index(a, get_min_node(a));
		a_size = a->size;
		if (a_min_index <= a_size / 2)
		{
			while (a_min_index-- > 0)
				ra(a,ctx);
		} else {
			while (a_min_index++ < a_size)
				rra(a,ctx);
		}
		pb(a, b,ctx);
	}
	while (b->size > 0)
		pa(a, b,ctx);
}
