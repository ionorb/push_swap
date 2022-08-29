/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:20:34 by myaccount         #+#    #+#             */
/*   Updated: 2022/08/29 20:38:57 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_median(t_stack *stack_a, t_stack *stack_b)
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

void	sort_big(t_stack *stack_a, t_stack *stack_b)
{
	split_median(stack_a, stack_b);
}

