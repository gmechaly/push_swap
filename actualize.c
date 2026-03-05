/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:18:55 by gmechaly          #+#    #+#             */
/*   Updated: 2024/10/25 19:35:34 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_actualize(t_stack **a, t_stack **b)
{
	ft_index_median_distance(*a);
	if (a && b)
	{
		ft_index_median_distance(*b);
		find_smaller_target(*a, *b);
		ft_cost(*a);
	}
}

void	ft_cost(t_stack *a)
{
	t_stack	*current_a;

	current_a = a;
	while (current_a)
	{
		if (current_a->above_median == current_a->target->above_median)
		{
			if (current_a->above_median == true)
				current_a->price = \
				ft_biggest(current_a->distance, current_a->target->distance);
		}
		else
		{
			ft_cost_not_same_side(current_a);
		}
		current_a = current_a->next;
	}
}

void	ft_cost_not_same_side(t_stack *current_a)
{
	if (current_a->above_median == true)
	{
		if (current_a->index > current_a->target->index / 2)
			current_a->price = current_a->target->index;
		else
			current_a->price = \
			current_a->distance + current_a->target->distance;
	}
	else
	{
		if (current_a->distance / 2 < current_a->target->distance)
			current_a->price = current_a->index;
		else
			current_a->price = \
			current_a->distance + current_a->target->distance;
	}
}

void	ft_index_median_distance(t_stack *lst)
{
	t_stack	*current;
	int		index;
	int		len;

	index = 0;
	len = ft_lstlen(lst);
	current = lst;
	while (current)
	{
		current->index = index;
		current->above_median = true;
		current->distance = index;
		if (index > len / 2)
		{
			current->above_median = false;
			current->distance = len - index;
		}
		if (current->next)
			current = current->next;
		else
			return ;
		index++;
	}
}

void	find_smaller_target(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*current_b;
	int		best_match_value;

	current_a = a;
	while (current_a)
	{
		current_b = b;
		best_match_value = INT_MIN;
		while (current_b)
		{
			if (current_b->value < current_a->value && \
				current_b->value > best_match_value)
			{
				best_match_value = current_b->value;
				current_a->target = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_value == INT_MIN)
			current_a->target = find_highest(b);
		current_a = current_a->next;
	}
}
