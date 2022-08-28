/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5n_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:42:18 by myaccount         #+#    #+#             */
/*   Updated: 2022/08/28 17:24:26 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
