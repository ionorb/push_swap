/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 20:57:26 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/05 23:14:33 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_to_val(t_stack *stack, int val)
{
	size_t	i;

	i = 0;
	if (stack->size == 0)
		return;
	while (stack->array[i] != val)
		i++;
	if (i >= stack->size)
		return;
	while (stack->size / 2 > i && ft_top(stack) != val)
		ft_revrotate(stack, '0');
	while (stack->size / 2 <= i && ft_top(stack) != val)
		ft_rotate(stack, '0');
}

void	rot_to_min(t_stack *stack)
{
	size_t	i;

	i = 0;
	if (stack->size == 0)
		return;
	while ((i < stack->size) && !(ft_ismin(stack, stack->array[i])))
		i++;
	while ((stack->size / 2 > i) && !(ft_ismin(stack, ft_top(stack))))
		ft_revrotate(stack, '0');
	while ((stack->size / 2 <= i) && !(ft_ismin(stack, ft_top(stack))))
		ft_rotate(stack, '0');
}

void	rot_to_max(t_stack *stack)
{
	size_t	i;

	i = 0;
	while ((i < stack->size) && !(ft_ismax(stack, stack->array[i])))
		i++;
	while ((stack->size / 2 > i) && !(ft_ismax(stack, ft_top(stack))))
		ft_revrotate(stack, '0');
	while ((stack->size / 2 <= i) && !(ft_ismax(stack, ft_top(stack))))
		ft_rotate(stack, '0');
}

int	get_max_between(t_stack *stack, int from, int to)
{
	int	*arr;
	int	max;
	int	i;

	i = 0;
	max = 0;
	arr = easy_sort(stack);
	while (i < (int)stack->size)
	{
		if (arr[i] > from && arr[i] <= to && arr[i] > max)
			max = arr[i];
		i++;
	}
	free(arr);
	return (max);
}

int	get_min_between(t_stack *stack, int from, int to)
{
	int	*arr;
	int	min;
	int	i;

	i = 0;
	min = get_max(stack);
	arr = easy_sort(stack);
	while (i < (int)stack->size)
	{
		if (arr[i] > from && arr[i] <= to && arr[i] < min)
			min = arr[i];
		i++;
	}
	free(arr);
	return (min);
}

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
