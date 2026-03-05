/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:03:04 by gmechaly          #+#    #+#             */
/*   Updated: 2024/10/25 19:03:36 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	ft_lstlen(t_stack *lst)
{
	int		i;
	t_stack	*temp;

	if (lst == NULL)
		return (0);
	i = 0;
	temp = lst;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

t_stack	*find_smallest(t_stack *lst)
{
	t_stack	*ptr;
	t_stack	*smallest;

	ptr = lst;
	smallest = ptr;
	while (ptr)
	{
		if (smallest->value > ptr->value)
			smallest = ptr;
		ptr = ptr->next;
	}
	return (smallest);
}

t_stack	*find_highest(t_stack *lst)
{
	t_stack	*ptr;
	t_stack	*highest;

	ptr = lst;
	highest = ptr;
	while (ptr)
	{
		if (highest->value < ptr->value)
			highest = ptr;
		ptr = ptr->next;
	}
	return (highest);
}

t_stack	*ft_lastnode(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_stack	*find_cheapest(t_stack *a)
{
	t_stack	*current_a;
	t_stack	*cheapest;
	int		price;

	current_a = a;
	price = INT_MAX;
	cheapest = NULL;
	while (current_a)
	{
		if (current_a->price < price)
		{
			price = current_a->price;
			cheapest = current_a;
		}
		current_a = current_a->next;
	}
	return (cheapest);
}
