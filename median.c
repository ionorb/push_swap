/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:20:34 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/04 23:28:44 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*easy_sort(t_stack *stack_a)
{
	size_t	i;
	size_t	j;
	int		swp;
	int		*arr;

	i = 0;
	j = -1;
	arr = malloc(stack_a->size * sizeof (int));
	while (++j < stack_a->size)
		arr[j] = stack_a->array[j];
	while (++i < stack_a->size)
	{
		j = -1;
		while (++j < stack_a->size)
		{
			if (arr[j] < arr[i])
			{
				swp = arr[i];
				arr[i] = arr[j];
				arr[j] = swp;
			}
		}
	}
	i = 0;
	return (arr);
}

int	ft_median(t_stack *stack_a)
{
	int	*arr;
	int	median;

	arr = easy_sort(stack_a);
	if (stack_a->size % 2 == 0)
		median = (arr[stack_a->size / 2 - 1] + arr[stack_a->size / 2]) / 2;
	else
		median = arr[stack_a->size / 2];
	free(arr);
	return (median);
}
/*
int	1st_quarter(t_stack *stack_a)
{
	int	*arr;
	int	median;

	arr = easy_sort(stack_a);
	if (stack_a->size % 2 == 0)
		median = (arr[stack_a->size / 2 - 1] + arr[stack_a->size / 2]) / 2;
	else
		median = arr[stack_a->size / 2];
	free(arr);
	return (median);
}

int	2st_quarter(t_stack *stack_a)
{
	int	*arr;
	int	median;

	arr = easy_sort(stack_a);
	if (stack_a->size % 2 == 0)
		median = (arr[stack_a->size / 2 - 1] + arr[stack_a->size / 2]) / 2;
	else
		median = arr[stack_a->size / 2];
	free(arr);
	return (median);
}

int	3rd_quarter(t_stack *stack_a)
{
	int	*arr;
	int	median;

	arr = easy_sort(stack_a);
	if (stack_a->size % 2 == 0)
		median = (arr[stack_a->size / 2 - 1] + arr[stack_a->size / 2]) / 2;
	else
		median = arr[stack_a->size / 2];
	free(arr);
	return (median);
}

int	4th_quarter(t_stack *stack_a)
{
	int	*arr;
	int	median;

	arr = easy_sort(stack_a);
	if (stack_a->size % 2 == 0)
		median = (arr[stack_a->size / 2 - 1] + arr[stack_a->size / 2]) / 2;
	else
		median = arr[stack_a->size / 2];
	free(arr);
	return (median);
}*/
