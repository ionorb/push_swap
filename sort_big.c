/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:20:34 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/05 12:53:54 by myaccount        ###   ########.fr       */
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

void	sort_big(t_stack *stack_a, t_stack *stack_b, int div)
{
	int	*arr;
	int	*med;
	int	i;

	i = 1;
	arr = easy_sort(stack_a);
	med = malloc((div + 1) * sizeof (int));
	med[0] = get_min(stack_a);
	while (i < div)
	{
		med[i] = arr[((stack_a->size) / div) * (div - i)];
		i++;
	}
	med[div] = get_max(stack_a) + 1;
	i = 0;
	while (i < div)
	{
		split_between(stack_a, stack_b, med[i], med[i + 1]);
		sort_half(stack_a, stack_b);
		i++;
	}
	while (!ft_issorted(stack_a))
		ft_rotate(stack_a, '0');
	free(arr);
}
