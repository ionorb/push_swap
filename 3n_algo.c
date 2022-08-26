/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3n_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 13:46:57 by myaccount         #+#    #+#             */
/*   Updated: 2022/08/26 20:53:13 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_which_case(t_stack *stack_a)
{
	int	*size_arr;
	int	final;
	int	i;
	int	base;

	i = 0;
	final = 0;
	base = 100;
	size_arr = (int *)ft_calloc(3, sizeof (int));
	if (stack_a->array[0] > stack_a->array[1])
		size_arr[0] = 1;
	if (stack_a->array[1] > stack_a->array[2])
		size_arr[1] = 1;
	if (stack_a->array[2] > stack_a->array[0])
		size_arr[2] = 1;
	while (i < 3)
	{
		final += size_arr[i] * base;
		base /= 10;
		i++;
	}
	return (final);
}

void	three_number_algo(t_stack *stack_a)
{
	int	whichone;
	int	i;

	i = 0;
	whichone = ft_which_case(stack_a);
	if (whichone == 100)
		ft_swap(stack_a);
	else if (whichone == 1)
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if (whichone == 101)
		ft_ra(stack_a);
	else if (whichone == 10)
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
	else if (whichone == 11)
		ft_rra(stack_a);
}
