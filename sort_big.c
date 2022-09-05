/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:20:34 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/06 01:20:52 by myaccount        ###   ########.fr       */
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

/*void	split_between(t_stack *stack_a, t_stack *stack_b, int from, int to)
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
}*/

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

/*int	get_index(t_stack *stack, int num)
{
	int	i;

	i = 0;
	while (stack->array[i] != num)
		i++;
	return (i);
}

int	get_index_sorted(t_stack *stack, int num)
{
	int	*arr;
	int	i;

	i = 0;
	arr = easy_sort(stack);
	while (arr[i] != num)
		i++;
	free(arr);
	return (i);
}
//
int	size_of_group(t_stack *stack, int from, int to)
{
	int	*arr;
	int	i;
	int	j;

	arr = easy_sort(stack);
	i = 0;
	j = 0;
	while (arr[i] != from)
		i++;
	while (arr[j] != to)
		j++;
	free(arr);
	if (j > i)
		return (j - i);
	return (i - j);
}*/

void	sort_between(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->size)
	{
		rot_to_val(stack_b, get_max(stack_b));
		ft_push(stack_b, stack_a);
	}
}

void	sort_big(t_stack *stack_a, t_stack *stack_b, int div)
{
	int	*arr;
	int	*med;
	int	asize;
	int	i;
	int	j;

	j = 0;
	i = 1;
	asize = stack_a->size;
	arr = easy_sort(stack_a);
	med = malloc((div + 1) * sizeof (int));
	med[0] = get_min(stack_a);
	while (i < div)
	{
		med[i] = arr[((stack_a->size) / div) * (div - i)];
		i++;
	}
	med[div] = get_max(stack_a);
	while (j + 2 <= div)
	{
		i = 0;
		asize = stack_a->size;
		while (i < asize)
		{
			if (ft_top(stack_a) >= med[j] && ft_top(stack_a) < med[j + 1])
			{
				ft_push(stack_a, stack_b);
				ft_rotate(stack_b, '0');
			}
			else if (ft_top(stack_a) >= med[j + 1] && ft_top(stack_a) < med[j + 2])
				ft_push(stack_a, stack_b);
			else
				ft_rotate(stack_a, '0');
			i++;
		}
		j += 2;
	}
	sort_between(stack_a, stack_b);
	free(arr);
}
