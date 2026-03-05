/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:06:45 by gmechaly          #+#    #+#             */
/*   Updated: 2024/10/24 16:43:55 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	return_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

void	*check_double(long *tab)
{
	int	i;
	int	index;

	index = 0;
	while (tab[index] != LONG_MAX)
	{
		i = 0;
		while (tab[i] != LONG_MAX)
		{
			if (tab[i] == tab[index] && i != index)
				return (NULL);
			i++;
		}
		index++;
	}
	return (&(*tab));
}

long int	*ft_parsing(int argc, char **argv)
{
	long	*tab;

	tab = create_tab(argc, argv);
	if (tab == NULL)
		return (NULL);
	if (check_double(tab) == NULL)
		return (free(tab), NULL);
	return (tab);
}

long int	*create_tab(int argc, char **argv)
{
	int			i;
	long int	*tab;

	i = 0;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (NULL);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (argv == NULL)
			return (NULL);
	}
	else
		argv++;
	tab = (long int *)malloc(sizeof(long) * (argvlen(argv) + 1));
	if (tab == NULL)
		return (free_argv(argv, argvlen(argv), argc), NULL);
	while (argv[i] != NULL)
	{
		tab[i] = ft_atol(argv[i]);
		if (tab[i++] == LONG_MIN)
			return (free_argv(argv, argvlen(argv), argc), free(tab), NULL);
	}
	tab[i] = LONG_MAX;
	return (free_argv(argv, argvlen(argv), argc), tab);
}
