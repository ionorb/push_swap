/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:48:20 by myaccount         #+#    #+#             */
/*   Updated: 2022/08/28 16:30:39 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printarray(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putnum(array[i]);
		write(1, " ", 1);
		i++;
	}
	write(1, "|\n", 2);
}

void	display_stacks(t_stack *stack_a, t_stack *stack_b)
{
	write(1, "a | ", 4);
	ft_printarray(stack_a->array, stack_a->size);
	write(1, "b | ", 4);
	ft_printarray(stack_b->array, stack_b->size);
}
