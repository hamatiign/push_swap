/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkajikaw <kkajikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 21:53:18 by kkajikaw          #+#    #+#             */
/*   Updated: 2026/09/16 22:06:28 by kkajikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stats_init(t_stats *stats)
{
	stats->total = 0;
	stats->sa = 0;
	stats->sb = 0;
	stats->ss = 0;
	stats->pa = 0;
	stats->pb = 0;
	stats->ra = 0;
	stats->rb = 0;
	stats->rr = 0;
	stats->rra = 0;
	stats->rrb = 0;
	stats->rrr = 0;
}