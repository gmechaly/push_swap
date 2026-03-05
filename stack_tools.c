/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:05:53 by gmechaly          #+#    #+#             */
/*   Updated: 2024/10/25 18:57:33 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	node_a_to_top(t_stack **a, t_stack *node)
{
	while (node->prev != NULL)
	{
		if (node->above_median == true)
			ra(a);
		else
			rra(a);
	}
	a = &node;
}

void	node_b_to_top(t_stack **b, t_stack *node)
{
	while (node->prev != NULL)
	{
		if (node->above_median == true)
			rb(b);
		else
			rrb(b);
	}
	b = &node;
}

void	nodes_ab_to_top(t_stack **a, t_stack **b, \
					t_stack *node_a, t_stack *target)
{
	while (node_a->index != 0 && target->index != 0)
	{
		if (node_a->above_median == target->above_median)
		{
			if (node_a->above_median == true)
				rr(a, b);
			else if (node_a->above_median == false)
				rrr(a, b);
		}
		else
			nodes_ab_to_top2(a, b, node_a, target);
		ft_index_median_distance(*a);
		ft_index_median_distance(*b);
	}
	if (target->index != 0)
		node_b_to_top(b, target);
	if (node_a->index != 0)
		node_a_to_top(a, node_a);
}

void	nodes_ab_to_top2(t_stack **a, t_stack **b, \
						t_stack *node_a, t_stack *target)
{
	if (node_a->above_median == true && node_a->index > target->index / 2)
		rrr(a, b);
	else if (target->above_median == true && \
	target->distance > node_a->distance / 2)
		rrr(a, b);
	else
	{
		if (target->index != 0)
			node_b_to_top(b, target);
		if (node_a->index != 0)
			node_a_to_top(a, node_a);
	}
}
