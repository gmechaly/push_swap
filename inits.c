/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:27:56 by gmechaly          #+#    #+#             */
/*   Updated: 2024/11/29 16:50:22 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	*append_node(int n, t_stack **a)
{
	t_stack	*node;

	node = ft_calloc(1, sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->value = n;
	node->next = NULL;
	if (!(*a))
	{
		a = &node;
		node->prev = NULL;
		node->next = NULL;
	}
	else
	{
		node->prev = ft_lastnode(*a);
		node->prev->next = node;
	}
	return (*a);
}

t_stack	*init_stack_a(long *tab)
{
	int		i;
	t_stack	*a;

	i = 0;
	a = NULL;
	while (tab[i] != LONG_MAX)
	{
		a = append_node(tab[i], &a);
		if (a == NULL)
			return (NULL);
		i++;
	}
	return (a);
}
