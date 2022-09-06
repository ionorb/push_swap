/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:56:57 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/06 09:29:04 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*easy_sort(t_stack *stack_a)
{
	size_t	i;
	size_t	j;
	int		swp;
	int		*arr;

	i = 0;
	j = -1;
	arr = malloc(stack_a->size * sizeof (int));
	while (++j < stack_a->size)
		arr[j] = stack_a->array[j];
	while (++i < stack_a->size)
	{
		j = -1;
		while (++j < stack_a->size)
		{
			if (arr[j] < arr[i])
			{
				swp = arr[i];
				arr[i] = arr[j];
				arr[j] = swp;
			}
		}
	}
	i = 0;
	return (arr);
}

void	ft_swap(t_stack *stack)
{
	int	swp;

	if (stack->size > 1)
	{
		swp = stack->array[stack->size - 1];
		stack->array[stack->size - 1] = stack->array[stack->size - 2];
		stack->array[stack->size - 2] = swp;
	}
	if (stack->type == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sa\n", 3);
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

void	ft_rotate(t_stack *stack)
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
	if (stack->type == 'b')
		write(1, "rb\n", 3);
	else if (stack->type == 'a')
		write(1, "ra\n", 3);
}

void	ft_revrotate(t_stack *stack)
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
	if (stack->type == 'b')
		write(1, "rb\n", 3);
	else if (stack->type == 'a')
		write(1, "ra\n", 3);
}
