/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:20:34 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/07 20:29:23 by myaccount        ###   ########.fr       */
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

int	val_above(t_stack *stack, int i)
{
	if (i == (int)stack->size - 1)
		return (stack->array[0]);
	return (stack->array[i + 1]);
}

int	val_below(t_stack *stack, int i)
{
	if (i == 0)
		return (stack->array[stack->size - 1]);
	return (stack->array[i - 1]);
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

/*int	ft_isvalid(t_stack *stack_a, int i, t_stack *stack_b, int j)
{

	if (((stack_a->array[i] > stack_b->array[j])
		&& (stack_a->array[i] < val_above(stack_b, j)
		|| (val_above(stack_b, j) == get_min(stack_b))))
		|| (stack_a->array[i] < get_min(stack_b)
		&& stack_b->array[j] == get_max(stack_b)))
		return (1);
	return (0);
}*/

int	ft_isvalid(t_stack *stack_a, int i, t_stack *stack_b, int j)
{

	if (((stack_a->array[i] < stack_b->array[j])
		&& (stack_a->array[i] > val_above(stack_b, j)
		|| (val_above(stack_b, j) == get_max(stack_b))))
		|| (stack_a->array[i] > get_max(stack_b)
		&& stack_b->array[j] == get_min(stack_b)))
		return (1);
	return (0);
}

void	place_inbetween(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (i < (int)stack_b->size)
	{
		if (ft_isvalid(stack_a, stack_a->size - 1, stack_b, i))
			break ;
		i++;
	}
	rot_to_val(stack_b, stack_b->array[i]);
	ft_push(stack_a, stack_b);
}

void	sort_big(t_stack *stack_a, t_stack *stack_b, int div)
{
	int	i;

	i = div;
	while (stack_a->size)
		ft_push(stack_a, stack_b);
	while (stack_b->size)
		place_inbetween(stack_b, stack_a);
	while (!ft_issorted(stack_a))
		ft_rotate(stack_a);
}

