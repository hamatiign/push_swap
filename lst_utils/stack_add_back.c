/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkajikaw <kkajikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 20:25:03 by kkajikaw          #+#    #+#             */
/*   Updated: 2026/09/17 20:25:04 by kkajikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_add_back(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	if (stack->head == NULL)
	{
		stack->head = node;
		stack->tail = node;
		stack->size++;
		return ;
	}
	stack->tail->next = node;
	stack->size++;
	node->prev = stack->tail;
	stack->tail = node;
}
