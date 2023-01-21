/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:20:34 by myaccount         #+#    #+#             */
/*   Updated: 2023/01/21 16:22:25 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	moves_to(t_stack *stack, int value)
// {
// 	size_t	index;

// 	index = 0;
// 	while (stack->array[index] != value)
// 		index++;
// 	if (index >= (stack->size - 1) / 2)
// 	{
// 		return ((stack->size - 1) - index);
// 	}
// 	else
// 	{
// 		return (index + 1);
// 	}
// }

void	sort_between(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->size)
	{
		rot_to_val(stack_b, get_max(stack_b));
		ft_push(stack_b, stack_a);
	}
}

int	*make_div_array(t_stack *stack_a, int div)
{
	int	i;
	int	*arr;
	int	*med;

	i = 1;
	arr = easy_sort(stack_a);
	med = malloc((div + 1) * sizeof (int));
	med[0] = get_min(stack_a);
	while (i < div)
	{
		med[i] = arr[((stack_a->size) / div) * (div - i)];
		i++;
	}
	med[div] = get_max(stack_a);
	free(arr);
	return (med);
}

void	push_or_rot(t_stack *stack_a, t_stack *stack_b, int *med, int j)
{
	if (ft_top(stack_a) >= med[j] && ft_top(stack_a) < med[j + 1])
	{
		ft_push(stack_a, stack_b);
		ft_rotate(stack_b);
	}
	else if (ft_top(stack_a) >= med[j + 1]
		&& ft_top(stack_a) < med[j + 2])
		ft_push(stack_a, stack_b);
	else
		ft_rotate(stack_a);
}

void	sort_big(t_stack *stack_a, t_stack *stack_b, int div)
{
	int	*med;
	int	asize;
	int	i;
	int	j;

	j = 0;
	asize = stack_a->size;
	med = make_div_array(stack_a, div);
	while (j + 2 <= div)
	{
		i = 0;
		asize = stack_a->size;
		while (i < asize)
		{
			push_or_rot(stack_a, stack_b, med, j);
			i++;
		}
		j += 2;
	}
	sort_between(stack_a, stack_b);
	free(med);
}
