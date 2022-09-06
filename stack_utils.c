/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:21:41 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/06 10:19:55 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_stack *stack)
{
	int	*arr;
	int	max;

	arr = easy_sort(stack);
	max = arr[0];
	free(arr);
	return (max);
}

int	get_min(t_stack *stack)
{
	int	*arr;
	int	min;

	arr = easy_sort(stack);
	min = arr[stack->size - 1];
	free(arr);
	return (min);
}

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

void	rot_to_val(t_stack *stack, int val)
{
	size_t	i;

	i = 0;
	if (stack->size == 0)
		return ;
	while (stack->array[i] != val)
		i++;
	if (i >= stack->size)
		return ;
	while (stack->size / 2 > i && ft_top(stack) != val)
		ft_revrotate(stack);
	while (stack->size / 2 <= i && ft_top(stack) != val)
		ft_rotate(stack);
}
