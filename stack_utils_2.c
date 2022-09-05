/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 20:57:26 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/05 10:40:26 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_to_min(t_stack *stack)
{
	size_t	i;

	i = 0;
	while ((i < stack->size) && !(ft_ismin(stack, stack->array[i])))
		i++;
	while ((stack->size / 2 > i) && !(ft_ismin(stack, ft_top(stack))))
		ft_revrotate(stack, '0');
	while ((stack->size / 2 <= i) && !(ft_ismin(stack, ft_top(stack))))
		ft_rotate(stack, '0');
}

void	rot_to_max(t_stack *stack)
{
	size_t	i;

	i = 0;
	while ((i < stack->size) && !(ft_ismax(stack, stack->array[i])))
		i++;
	while ((stack->size / 2 > i) && !(ft_ismax(stack, ft_top(stack))))
		ft_revrotate(stack, '0');
	while ((stack->size / 2 <= i) && !(ft_ismax(stack, ft_top(stack))))
		ft_rotate(stack, '0');
}

int	get_max(t_stack *stack)
{
	int	i;

	i = 0;
	while (!ft_ismax(stack, stack->array[i]))
		i++;
	return (stack->array[i]);
}

int	get_min(t_stack *stack)
{
	int	i;

	i = 0;
	while (!ft_ismin(stack, stack->array[i]))
		i++;
	return (stack->array[i]);
}
