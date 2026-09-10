#include "../push_swap.h"

static int	get_min_node(t_stack *stack)
{
	t_node	*node;
	int		min;

	node = stack->head;
	min = node->value;
	while (node->next)
	{
		node = node->next;
		if (node->value < min)
			min = node->value;
	}
	return (min);
}

static int	get_node_index(t_stack *stack, int value)
{
	t_node	*node;
	int		index;

	node = stack->head;
	index = 0;
	while (node)
	{
		if (node->value == value)
			return (index);
		node = node->next;
		index++;
	}
	return (-1);
}

static int	is_sorted(t_stack *stack)
{
	t_node	*node;

	node = stack->head;
	while (node->next)
	{
		if(node->value > node->next->value)
			return(0);
		node = node->next;
	}
	return(1);
}

void		simple_sort(t_stack *a, t_stack *b)
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
				ra(a);
		} else {
			while (a_min_index++ < a_size)
				rra(a);
		}
		pb(a, b);
	}
	while (b->size > 0)
		pa(a, b);
}
