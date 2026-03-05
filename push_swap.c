/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:20:45 by gmechaly          #+#    #+#             */
/*   Updated: 2024/10/25 19:42:51 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	*push_swap(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	pb(a, b);
	pb(a, b);
	while (ft_lstlen(*a) > 3)
	{
		cheapest = find_cheapest(*a);
		nodes_ab_to_top(a, b, cheapest, cheapest->target);
		pb(a, b);
	}
	sort_three(a);
	node_b_to_top(b, find_highest(*b));
	while (ft_lstlen(*b) != 0)
	{
		ft_actualize(a, b);
		find_bigger_target(*a, *b);
		node_a_to_top(a, (*b)->target);
		pa(a, b);
	}
	ft_index_median_distance(*a);
	node_a_to_top(a, find_smallest(*a));
	if (is_sorted(*a) == true)
		return (a);
	else
		return (NULL);
}

void	find_bigger_target(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*current_b;
	int		best_match_value;

	current_b = b;
	while (current_b)
	{
		current_a = a;
		best_match_value = INT_MAX;
		while (current_a)
		{
			if (current_a->value > current_b->value && \
				current_a->value < best_match_value)
			{
				best_match_value = current_a->value;
				current_b->target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_value == INT_MAX)
			current_b->target = find_smallest(a);
		current_b = current_b->next;
	}
}

void	sort_three(t_stack **a)
{
	t_stack	*max;

	if (is_sorted(*a))
		return ;
	max = find_highest(*a);
	if (*a == max)
		ra(a);
	else if ((*a)->next == max)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

bool	is_sorted(t_stack *stack)
{
	t_stack	*clone;

	clone = stack;
	while (clone->next)
	{
		if (clone->value > clone->next->value)
			return (false);
		clone = clone->next;
	}
	return (true);
}
