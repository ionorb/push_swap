/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:56:57 by myaccount         #+#    #+#             */
/*   Updated: 2022/08/22 19:09:31 by myaccount        ###   ########.fr       */
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
	int	*array_from;
	int	*array_to;
	size_t	i;

	if (from->size > 0)
	{
		i = 0;
		array_from = malloc((from->size - 1) * sizeof (int));
		array_to = malloc((to->size + 1) * sizeof (int));
		while (i < from->size - 1)
		{
			array_from[i] = from->array[i];
			i++;
		}
		i = 0;
		while (i < to->size)
		{
			array_to[i] = to->array[i];
			i++;
		}
		array_to[i] = from->array[from->size - 1];
		free(from->array);
		free(to->array);
		from->array = array_from;
		from->size -= 1;
		to->array = array_to;
		to->size += 1;
	}
}
