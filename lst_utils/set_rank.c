
#include "../push_swap.h"

void set_rank(t_stack *stack)
{
	t_node	*node;
	t_node	*i;
	int		value;
	int		rank;

	node = stack->head;
	while (node)
	{
		value = node->value;
		rank = 0;
		i = stack->head;
		while (i)
		{
			if (value > i->value)
				rank++;
			i = i->next;
		}
		node->rank = rank;
		node = node->next;
	}
}






