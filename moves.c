/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 00:22:47 by gmechaly          #+#    #+#             */
/*   Updated: 2024/10/25 18:29:22 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	swap(t_stack **a)
{
	if (ft_lstlen(*a) < 2)
		return ;
	(*a)->prev = (*a)->next;
	(*a)->next = (*a)->next->next;
	(*a)->next->prev->next = (*a);
	(*a)->prev->prev = NULL;
	(*a)->next->prev = (*a);
	(*a) = (*a)->prev;
}

void	push(t_stack **dst, t_stack **src)
{
	if (ft_lstlen(*src) < 1)
		return ;
	if (!(*dst) && (*src)->next)
	{
		*dst = *src;
		*src = (*src)->next;
		(*src)->prev = NULL;
		(*dst)->prev = NULL;
		(*dst)->next = NULL;
	}
	else if (!(*src)->next)
	{
		(*dst)->prev = (*src);
		(*src)->next = (*dst);
		(*dst) = (*dst)->prev;
		(*src) = NULL;
	}
	else
	{
		(*src) = (*src)->next;
		(*src)->prev->next = (*dst);
		(*dst)->prev = (*src)->prev;
		(*dst) = (*dst)->prev;
		(*src)->prev = NULL;
	}
}

void	revrotate(t_stack **a)
{
	t_stack	*last_node;

	last_node = ft_lastnode(*a);
	last_node->next = (*a);
	last_node->prev->next = NULL;
	(*a)->prev = last_node;
	last_node->prev = NULL;
	(*a) = (*a)->prev;
}

void	rotate(t_stack **a)
{
	t_stack	*last_node;

	last_node = ft_lastnode(*a);
	(*a)->prev = last_node;
	last_node->next = (*a);
	(*a) = (*a)->next;
	(*a)->prev->next = NULL;
	(*a)->prev = NULL;
}
