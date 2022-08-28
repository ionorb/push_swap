/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5n_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:42:18 by myaccount         #+#    #+#             */
/*   Updated: 2022/08/28 16:02:12 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_ismax(t_stack *stack, int n)
{
	size_t	i;
	int		max;

	max = 0;
	i = 0;
	while (i < stack->size)
	{
		if (stack->array[i] > max)
			max = stack->array[i];
		i++;
	}
	if (n >= max)
		return (1);
	return (0);
}

int	ft_ismin(t_stack *stack, int n)
{
	size_t	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->array[i] < n)
			return (0);
		i++;
	}
	return (1);
}

void	rot_to_min(t_stack *stack)
{
	size_t	i;

	i = 0;
	while ((i < stack->size) && !(ft_ismin(stack, stack->array[i])))
		i++;
	while ((stack->size / 2 > i) && !(ft_ismin(stack, ft_top(stack))))
		ft_rra(stack);
	while ((stack->size / 2 <= i) && !(ft_ismin(stack, ft_top(stack))))
		ft_ra(stack);
}

void	four_number_algo(t_stack *stack_a, t_stack *stack_b)
{
	rot_to_min(stack_a);
	ft_push(stack_a, stack_b);
	three_number_algo(stack_a);
	ft_push(stack_b, stack_a);
}

void	five_number_algo(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 4)
		four_number_algo(stack_a, stack_b);
	else
	{
		rot_to_min(stack_a);
		ft_push(stack_a, stack_b);
		rot_to_min(stack_a);
		ft_push(stack_a, stack_b);
		three_number_algo(stack_a);
		ft_push(stack_b, stack_a);
		ft_push(stack_b, stack_a);
	}
}
