/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:20:34 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/05 10:33:41 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_between(t_stack *stack_a, t_stack *stack_b, int from, int to)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = stack_a->size;
	while (ft_top(stack_a) < from)
		ft_rotate(stack_a, '0');
	while (i < size && ft_top(stack_a) >= from && !ft_issorted(stack_a))
	{
		if (ft_top(stack_a) >= from && ft_top(stack_a) < to)
			ft_push(stack_a, stack_b);
		else
		{
			ft_rotate(stack_a, '0');
		}
		i++;
	}
	while (ft_top(stack_a) <= from + 1 && !ft_issorted(stack_a))
		ft_rotate(stack_a, '0');
}

int		moves_to(t_stack *stack, int value)
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

void	sort_half(t_stack *stack_a, t_stack *stack_b)
{
	int	max;
	int	min;

	while (stack_b->size)
	{
		max = get_max(stack_b);
		min = get_min(stack_b);
		if (moves_to(stack_b, max) < moves_to(stack_b, min))
		{
			rot_to_max(stack_b);
			ft_push(stack_b, stack_a);
		}
		else
		{
			rot_to_min(stack_b);
			ft_push(stack_b, stack_a);
			ft_rotate(stack_a, '0');
		}
	}
}

void	sort_big(t_stack *stack_a, t_stack *stack_b)
{
	int	median;
	int	first;
	int third;
	int	max;

	max = get_max(stack_a);
	median = ft_median(stack_a);
	first = median / 2;
	third = (median + max) / 2;
	split_between(stack_a, stack_b, 0, first);
	sort_half(stack_a, stack_b);
	split_between(stack_a, stack_b, first, median);
	sort_half(stack_a, stack_b);
	split_between(stack_a, stack_b, median, third);
	sort_half(stack_a, stack_b);
	split_between(stack_a, stack_b, third, max + 1);
	sort_half(stack_a, stack_b);
	while (!ft_issorted(stack_a))
		ft_rotate(stack_a, '0');
}

/*
void	sort_big(t_stack *stack_a, t_stack *stack_b)
{
	int	median;
	int	max;

	median = ft_median(stack_a);
	max = get_max(stack_a);
	split_between(stack_a, stack_b, 0, median);
	sort_half(stack_a, stack_b);
	split_between(stack_a, stack_b, median, max + 1);
	sort_half(stack_a, stack_b);
	while (!ft_issorted(stack_a))
		ft_rotate(stack_a, '0');
}*/
