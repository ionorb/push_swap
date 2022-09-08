/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:35:08 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/08 18:04:34 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_contains_dup(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[j])
		{
			if (j != i && ft_atoi(av[j]) == ft_atoi(av[i]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_parsing(char **av)
{
	int		i;

	i = 0;
	while (av[i])
	{
		if (!ft_isnum(av[i]) || ft_atoi(av[i]) > 2147483647 || ft_atoi(av[i]) < -2147483647)
			return (-1);
		i++;
	}
	if (ft_contains_dup(av))
		return (-1);
	return (ft_get_stack_size(av));
}
