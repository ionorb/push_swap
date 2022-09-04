/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:20:34 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/04 21:28:03 by myaccount        ###   ########.fr       */
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
			ft_ra(stack_a);
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
		if(ft_top(stack_a) >= median)
			ft_push(stack_a, stack_b);
		else
			ft_ra(stack_a);
		i++;
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
		return (stack->size - 1 - index);
	else
		return (index + 1);
}

void	sort_half(t_stack *stack_a, t_stack *stack_b)
{
	int	min;
	int	max;

	min = get_min(stack_b);
	max = get_max(stack_b);
	while (stack_b->size)
	{
		if (moves_to(stack_b, max) < moves_to(stack_b, min))
		{
			rot_to_max(stack_b);
			ft_push(stack_b, stack_a);
		}
		else
		{
			rot_to_min(stack_b);
			ft_push(stack_b, stack_a);
			ft_ra(stack_a);
		}
	}
}

void	sort_big(t_stack *stack_a, t_stack *stack_b)
{
	split_median_lower(stack_a, stack_b);
	sort_half(stack_a, stack_b);
	split_median_upper(stack_a, stack_b);
	sort_half(stack_a, stack_b);
	while (!ft_issorted(stack_a))
		ft_ra(stack_a);
}
