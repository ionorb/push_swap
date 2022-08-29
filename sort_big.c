/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:20:34 by myaccount         #+#    #+#             */
/*   Updated: 2022/08/30 00:15:03 by myaccount        ###   ########.fr       */
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
}

void	rot_to_max(t_stack *stack)
{
}

int		moves_to(t_stack *stack, int value)
{
}

void	sort_half(t_stack *stack_a, t_stack *stack_b)
{
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
}
