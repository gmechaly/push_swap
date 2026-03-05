/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 00:22:12 by gmechaly          #+#    #+#             */
/*   Updated: 2024/11/29 16:50:47 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	long	*tab;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	tab = ft_parsing(argc, argv);
	if (tab == NULL)
		return (return_error());
	stack_a = init_stack_a(tab);
	if (stack_a == NULL)
		return (free(tab), 0);
	free (tab);
	if (ft_lstlen(stack_a) <= 3)
		sort_three(&stack_a);
	else if (is_sorted(stack_a) || push_swap(&stack_a, &stack_b) == NULL)
		return (free_stack(&stack_a, &stack_b), 0);
	free_stack(&stack_a, &stack_b);
}
