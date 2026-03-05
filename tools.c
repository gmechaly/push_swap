/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:50:31 by gmechaly          #+#    #+#             */
/*   Updated: 2024/10/25 19:10:29 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	argvlen(char **argv)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	if (!ft_isnumeric(argv[0]))
		i++;
	while (argv[i + len])
		len++;
	return (len);
}

void	*ft_isnumeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] <= '0' && str[i] >= '9')
			return (NULL);
		i++;
	}
	return (&(*str));
}

int	ft_biggest(int x, int y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

long int	ft_atol(char *nbr)
{
	int			i;
	int			sign;
	long int	result;

	i = 0;
	result = 0;
	sign = 1;
	while ((nbr[i] <= '\r' && nbr[i] >= '\t') || nbr[i] == ' ')
		i++;
	if (nbr[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (!(nbr[i] >= '0' && nbr[i] <= '9'))
		return (LONG_MIN);
	while (nbr[i] >= '0' && nbr[i] <= '9')
	{
		result = result * 10;
		result = result + nbr[i] - '0';
		i++;
	}
	if (sign * result > 2147483647 || sign * result < -2147483648)
		return (LONG_MIN);
	return (sign * result);
}
