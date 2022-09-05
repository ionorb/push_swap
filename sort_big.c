/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:20:34 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/05 10:23:20 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_median_lower(t_stack *stack_a, t_stack *stack_b)
{
	size_t	i;
	int		median;
	size_t	size;

	i = 0;
	size = stack_a->size;
	median = ft_median(stack_a);
	while (i < size)
	{
		//printf("%d\n", ft_top(stack_a));
		if(ft_top(stack_a) < median)
			ft_push(stack_a, stack_b);
		else
			ft_rotate(stack_a, '0');
		i++;
	}
}

void	split_median_upper(t_stack *stack_a, t_stack *stack_b)
{
	size_t	i;
	int		median;
	size_t	size;

	i = 0;
	size = stack_a->size;
	median = ft_median(stack_a);
	while (i < size)
	{
		//printf("%d\n", ft_top(stack_a));
		if (ft_top(stack_a) >= median)
			ft_push(stack_a, stack_b);
		else if (!ft_issorted(stack_a))
			ft_rotate(stack_a, '0');
		i++;
	}
}

int	is_closest(t_stack *stack, int top, int val)
{
	int	i;
	int	*arr;
	int	closest;

	arr = easy_sort(stack);
	i = 0;
	while (stack->array[i] < val)
		i++;
	if (i == 0)
		closest = stack->array[i];
	else if (i != 0 && stack->array[i] - val < val - stack->array[i - 1])
		closest = stack->array[i];
	else
		closest = stack->array[i - 1];
	if (top == closest)
		return (1);
	else
		return (0);
	free(arr);
}

void	split_between(t_stack *stack_a, t_stack *stack_b, int from, int to)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = stack_a->size;
	while (ft_top(stack_a) < from)
	{
		//printf("\ntop:%d, from:%d\n", ft_top(stack_a), from);
		//display_stacks(stack_a, stack_b);
		ft_rotate(stack_a, '0');
	}
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
	{
		//write(1, "ban", 3);
		//display_stacks(stack_a, stack_b);
		ft_rotate(stack_a, '0');
	}
}

int		moves_to(t_stack *stack, int value)
{
	size_t	index;

	index = 0;
	while (stack->array[index] != value)
		index++;
/*	0 1 2 3 4 5 6   size: 7 = 6
	0 1 2 3 4 5		size: 6 = 5
	0 1 2			size: 3 = 2
	0 1 2 3 4 5 6 7 8 9 10		size 11 = 10
	0 1 2 3 4 5 6 7 8 9 10 11 	size 12 = 11*/
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
		//printf("\nmoves to max(%d):%d  moves to min(%d):%d\n", get_max(stack_b), moves_to(stack_b, get_max(stack_b)), get_min(stack_b), moves_to(stack_b, get_min(stack_b)));
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
	int	max;

	median = ft_median(stack_a);
	max = get_max(stack_a);
	//split_median_lower(stack_a, stack_b);
	split_between(stack_a, stack_b, 0, median);
	sort_half(stack_a, stack_b);
	//split_median_upper(stack_a, stack_b);
	split_between(stack_a, stack_b, median, max + 1);
	sort_half(stack_a, stack_b);
	while (!ft_issorted(stack_a))
		ft_rotate(stack_a, '0');
}
