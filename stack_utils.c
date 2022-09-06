/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:21:41 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/06 01:28:50 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_top(t_stack *stack)
{
	return (stack->array[stack->size - 1]);
}

int	ft_issorted(t_stack *stack)
{
	size_t	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->array[i] < stack->array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_ismax(t_stack *stack, int n)
{
	int		*arr;
	int		max;

	arr = easy_sort(stack);
	max = arr[0];
	free(arr);
	if (n == max)
		return (1);
	return (0);
}

int	ft_ismin(t_stack *stack, int n)
{
	int	*arr;
	int	min;

	arr = easy_sort(stack);
	min = arr[stack->size - 1];
	free(arr);
	if (n == min)
		return (1);
	return (0);
}
