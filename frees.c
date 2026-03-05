/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 20:26:31 by gmechaly          #+#    #+#             */
/*   Updated: 2024/10/23 16:21:35 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	*free_argv(char **argv, int len, int argc)
{
	int	i;

	i = 0;
	if (argc != 2)
		return (NULL);
	while (i <= len)
	{
		free(argv[i]);
		i++;
	}
	free (argv);
	return (NULL);
}

void	*free_stack(t_stack **a, t_stack **b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstlen(*a);
	len_b = ft_lstlen(*b);
	while (len_a >= 1 || len_b >= 1)
	{
		if (len_a == 1)
			free(*a);
		else if (len_a > 1)
		{
			*a = (*a)->next;
			free((*a)->prev);
		}
		len_a--;
		if (len_b == 1)
			free(*b);
		else if (len_b > 1)
		{
			*b = (*b)->next;
			free((*b)->prev);
		}
		len_b--;
	}
	return (NULL);
}
