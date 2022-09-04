/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:56:57 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/04 23:57:23 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack)
{
	int	swp;

	if (stack->size > 1)
	{
		swp = stack->array[stack->size - 1];
		stack->array[stack->size - 1] = stack->array[stack->size - 2];
		stack->array[stack->size - 2] = swp;
	}
}

void	ft_push(t_stack *from, t_stack *to)
{
	int		*array_to;
	size_t	i;

	if (from->size > 0)
	{
		i = -1;
		array_to = malloc((to->size + 1) * sizeof (int));
		i = -1;
		while (++i < to->size)
			array_to[i] = to->array[i];
		array_to[i] = from->array[from->size - 1];
		free(to->array);
		from->size -= 1;
		to->array = array_to;
		to->size += 1;
	}
	if (to->type == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}

void	ft_rotate(t_stack *stack, char which)
{
	int	tmp;
	int	i;

	if (stack->size > 1)
	{
		i = stack->size - 1;
		tmp = stack->array[stack->size - 1];
		while (i > 0)
		{
			stack->array[i] = stack->array[i - 1];
			i--;
		}
		stack->array[0] = tmp;
	}
	if (which == 'r')
		write(1, "rr\n", 3);
	else if (stack->type == 'b')
		write(1, "rb\n", 3);
	else if (stack->type == 'a')
		write(1, "ra\n", 3);
	else
		write(1, "WHAAAA!\n", 8);
}

void	ft_revrotate(t_stack *stack, char which)
{
	int		tmp;
	size_t	i;

	if (stack->size > 1)
	{
		i = 0;
		tmp = stack->array[0];
		while (i < stack->size - 1)
		{
			stack->array[i] = stack->array[i + 1];
			i++;
		}
		stack->array[stack->size - 1] = tmp;
	}
	if (which == 'r')
		write(1, "rrr\n", 4);
	else if (stack->type == 'b')
		write(1, "rrb\n", 4);
	else if (stack->type == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "WHAAAA!\n", 8);
}

void	ft_rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_revrotate(stack_a, 'r');
	ft_revrotate(stack_b, 'r');
	write(1, "rrr\n", 4);
}
