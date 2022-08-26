/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:55:17 by myaccount         #+#    #+#             */
/*   Updated: 2022/08/26 20:31:09 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *stack_a)
{
	ft_rotate(stack_a);
	write(1, "ra\n", 3);
}

void	ft_rb(t_stack *stack_b)
{
	ft_rotate(stack_b);
	write(1, "rb\n", 3);
}

void	ft_rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	write(1, "rr\n", 3);
}

void	ft_rra(t_stack *stack_a)
{
	ft_revrotate(stack_a);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack *stack_b)
{
	ft_revrotate(stack_b);
	write(1, "rrb\n", 4);
}
