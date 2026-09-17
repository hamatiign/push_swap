/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rank.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkajikaw <kkajikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 20:25:48 by kkajikaw          #+#    #+#             */
/*   Updated: 2026/09/17 20:25:53 by kkajikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_rank(t_stack *stack)
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
