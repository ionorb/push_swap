/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 20:57:26 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/06 01:29:34 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		ft_revrotate(stack, '0');
	while (stack->size / 2 <= i && ft_top(stack) != val)
		ft_rotate(stack, '0');
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
