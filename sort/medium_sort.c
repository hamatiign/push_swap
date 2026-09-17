/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkajikaw <kkajikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 19:16:49 by kkajikaw          #+#    #+#             */
/*   Updated: 2026/09/17 21:38:04 by kkajikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <math.h>

static int	ceil_sqrt(int n)
{
	int	ans;

	ans = 0;
	while (ans * ans <= n)
		ans++;
	return (ans - 1);
}

void	medium_sort(t_stack *a, t_stack *b, t_context *ctx)
{
	const int	chunk_size = ceil_sqrt(a->size);
	int			chunk_number;
	int			size;
	int			max_node_index;

	chunk_number = 0;
	while (a->size > 0)
	{
		size = a->size;
		while (size-- > 0)
		{
			if (a->head->rank >= chunk_size * chunk_number
				&& a->head->rank < chunk_size * (chunk_number + 1))
			{
				pb(a, b, ctx);
			}
			else
				ra(a, ctx);
		}
		chunk_number++;
	}
	while (b->head)
	{
		max_node_index = get_node_index(b, get_max_node(b));
		if (max_node_index <= b->size / 2)
		{
			while (max_node_index-- > 0)
				rb(b, ctx);
		}
		else
		{
			while (max_node_index++ < b->size)
				rrb(b, ctx);
		}
		pa(a, b, ctx);
	}
}
