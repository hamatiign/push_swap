#include "../push_swap.h"

static int	get_max_bits(int size)
{
	int	bits;
	int	max;

	bits = 0;
	max = size - 1;
	while (max > 0)
	{
		max = max >> 1;
		bits++;
	}
	return (bits);
}

void	complex_sort(t_stack *a, t_stack *b, t_context *ctx)
{
	int		max_bits;
	int		bit;
	int		a_size;
	int		i;
	
	a_size = a->size;
	max_bits = get_max_bits(a_size);
	bit	= 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i++ < a_size)
		{
			if ((a->head->rank >> bit) & 1)
				ra(a, ctx);
			else
				pb(a, b, ctx);
		}
		while (b->head)
			pa(a, b, ctx);
		bit++;
	}
}
