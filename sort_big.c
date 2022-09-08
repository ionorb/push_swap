/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:20:34 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/08 00:46:28 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	moves_to(t_stack *stack, int value)
{
	size_t	index;

	index = 0;
	while (stack->array[index] != value)
		index++;
	if (index >= (stack->size - 1) / 2)
	{
		return ((stack->size - 1) - index);
	}
	else
	{
		return (index + 1);
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

int	val_above(t_stack *stack, int i)
{
	if (i == (int)stack->size - 1)
		return (stack->array[0]);
	return (stack->array[i + 1]);
}

int	ft_isvalid(t_stack *stack_a, int i, t_stack *stack_b, int j)
{
	int	a;
	int	b;
	int	above;
	int	max;
	int	min;

	a = stack_a->array[i];
	b = stack_b->array[j];
	above = val_above(stack_a, i);
	max = get_max(stack_a);
	min = get_min(stack_a);
	if (((b < a) && (b > above || (above == max))))
		return (1);
	return (0);
}

void	place_inbetween(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = (int)stack_a->size - 1;
	while (i >= 0)
	{
		if (ft_isvalid(stack_a, i, stack_b, stack_b->size - 1))
			break ;
		i--;
	}
	rot_to_val(stack_a, stack_a->array[i]);
	ft_push(stack_b, stack_a);
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
	while (j <= div)
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
	while (stack_b->size)
		place_inbetween(stack_a, stack_b);
	rot_to_val(stack_a, get_min(stack_a));
	free(med);
}

