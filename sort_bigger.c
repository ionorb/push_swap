/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bigger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 00:53:17 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/05 10:23:53 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_bigger(t_stack *stack_a, t_stack *stack_b)
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
	//printf("\nthird:%d, max:%d", third, max);
	split_between(stack_a, stack_b, third, max + 1);
	sort_half(stack_a, stack_b);
	while (!ft_issorted(stack_a))
		ft_rotate(stack_a, '0');
	return (0);
}
