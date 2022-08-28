/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:35:08 by myaccount         #+#    #+#             */
/*   Updated: 2022/08/28 17:17:16 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_contains_dup(char **av)
{
	int	size;
	int	i;
	int	j;
	int	*arr;

	size = ft_get_stack_size(av);
	j = size - 1;
	arr = malloc(size * sizeof (int));
	while (j >= 0)
	{
		i = 0;
		while (i <= size - 1)
		{
			if (arr[i] == atoi(av[j]))
				return (1);
			i++;
		}
		arr[j] = atoi(av[j]);
		j--;
	}
	free(arr);
	return (0);
}

int	ft_parsing(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!ft_isnum(av[i]))
			return (0);
		i++;
	}
	if (ft_contains_dup(av))
		return (0);
	write(1, "ban\n", 4);
	return (1);
}
