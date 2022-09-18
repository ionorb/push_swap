/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:42:18 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/17 16:33:10 by yridgway         ###   ########.fr       */
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
	free(size_arr);
	return (final);
}

void	three_number_algo(t_stack *stack_a)
{
	int	whichone;

	whichone = ft_which_case(stack_a);
	if (whichone == 100)
		ft_swap(stack_a);
	else if (whichone == 1)
	{
		ft_swap(stack_a);
		ft_revrotate(stack_a);
	}
	else if (whichone == 101)
		ft_rotate(stack_a);
	else if (whichone == 10)
	{
		ft_swap(stack_a);
		ft_rotate(stack_a);
	}
	else if (whichone == 11)
		ft_revrotate(stack_a);
}

void	four_number_algo(t_stack *stack_a, t_stack *stack_b)
{
	rot_to_val(stack_a, get_min(stack_a));
	ft_push(stack_a, stack_b);
	three_number_algo(stack_a);
	ft_push(stack_b, stack_a);
}

void	five_number_algo(t_stack *stack_a, t_stack *stack_b)
{
	rot_to_val(stack_a, get_min(stack_a));
	ft_push(stack_a, stack_b);
	rot_to_val(stack_a, get_min(stack_a));
	ft_push(stack_a, stack_b);
	three_number_algo(stack_a);
	ft_push(stack_b, stack_a);
	ft_push(stack_b, stack_a);
}

void	sort_small_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 3)
		three_number_algo(stack_a);
	else if (stack_a->size == 4)
		four_number_algo(stack_a, stack_b);
	else if (stack_a->size == 5)
		five_number_algo(stack_a, stack_b);
}
