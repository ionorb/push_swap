/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:20:34 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/06 22:40:51 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	moves_to(t_stack *stack, int value)
{
	size_t	index;

	index = 0;
	while (stack->array[index] != value)
		index++;
	if (index >= (stack->size - 1) / 2)
	{
		return ((stack->size - 1) - index);
	}
	else
	{
		return (index + 1);
	}
}

void	sort_between(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->size)
	{
		rot_to_val(stack_b, get_max(stack_b));
		ft_push(stack_b, stack_a);
	}
}

int	*make_div_array(t_stack *stack_a, int div)
{
	int	i;
	int	*arr;
	int	*med;

	i = 1;
	arr = easy_sort(stack_a);
	med = malloc((div + 1) * sizeof (int));
	med[0] = get_min(stack_a);
	while (i < div)
	{
		med[i] = arr[((stack_a->size) / div) * (div - i)];
		i++;
	}
	med[div] = get_max(stack_a);
	free(arr);
	return (med);
}

void	push_or_rot(t_stack *stack_a, t_stack *stack_b, int *med, int j)
{
	if (ft_top(stack_a) >= med[j] && ft_top(stack_a) < med[j + 1])
	{
		ft_push(stack_a, stack_b);
		ft_rotate(stack_b);
	}
	else if (ft_top(stack_a) >= med[j + 1]
		&& ft_top(stack_a) < med[j + 2])
		ft_push(stack_a, stack_b);
	else
		ft_rotate(stack_a);
}

int	get_next_smaller(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (int)stack_b->size)
	{
		if (ft_top(stack_a) > stack_b->array[i])
			break ;
		i++;
	}
	while (j < (int)stack_b->size)
	{
		if (ft_top(stack_a) > stack_b->array[stack_b->size - 1 - i])
			break ;
		j++;
	}
	if (i == (int)stack_b->size)
		write(1, "bam\n", 4);
	if (j <= i)
		return (stack_b->array[j]);
	return (stack_b->array[i]);
}

int	get_next_bigger(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (int)stack_b->size)
	{
		if (ft_top(stack_a) < stack_b->array[i])
			break ;
		i++;
	}
	while (j < (int)stack_b->size)
	{
		if (ft_top(stack_a) < stack_b->array[stack_b->size - 1 - i])
			break ;
		j++;
	}
	if (i == (int)stack_b->size)
		write(1, "bam\n", 4);
	if (j <= i)
		return (stack_b->array[j]);
	return (stack_b->array[i]);
}

int	val_ahead(t_stack *stack, int i)
{
	if (i == (int)stack->size - 1)
		return (stack->array[0]);
	return (stack->array[i - 1]);
}

int	count_rot_a(t_stack *stack_a, int val)
{
	int	i;

	i = 0;
	while (i < (int)stack_a->size)
	{
		if (val < stack_a->array[i]
			&& (val > val_ahead(stack_a, i)
			|| val_ahead(stack_a, i) == get_max(stack_a)))
			break ;
		i++;
	}
	if (i >= ((int)stack_a->size - 1) / 2)
		return ((int)stack_a->size - 1 - i);
	return (i);
}

int	count_rot_b(t_stack *stack_a, t_stack *stack_b, int val, int j)
{
	int	i;

	i = 0;
	while (i < (int)stack_b->size)
	{
		if (stack_b->array[i] < val
			&& (stack_b->array[i] > val_ahead(stack_a, j)
			|| val_ahead(stack_a, j) == get_max(stack_a)))
			break ;
		i++;
	}
	if (i >= ((int)stack_b->size - 1) / 2)
		return ((int)stack_b->size - 1 - i);
	return (i);
}

void	rotate_to_closeset(t_stack *stack_a, t_stack *stack_b)
{
	int	min;
	int	i;
	int	j;
	int	acount;
	int	bcount;
	int	aval;
	int	bval;

	i = 0;
	min = stack_b->size + stack_a->size;
	while (i < (int)stack_a->size)
	{
		bcount = count_rot_b(stack_a, stack_b, stack_a->array[i], i);
		j = 0;
		while (j < (int)stack_b->size)
		{
			acount = count_rot_a(stack_a, stack_b->array[j]);
			if (bcount + acount < min)
			{
				min = bcount + acount;
				aval = stack_a->array[i];
				bval = stack_b->array[j];
			}
			j++;
		}
		i++;
	}
	rot_to_val(stack_a, aval);
	rot_to_val(stack_b, bval);
//	printf("aval:%d   bval: %d\n", aval, bval);
//	display_stacks(stack_a, stack_b);
}

int	ft_bottom(t_stack *stack)
{
	return (stack->array[0]);
}

void	rot_to_pos(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	if (stack_a->size < 2)
		ft_push(stack_b, stack_a);
	while (i + 1 < (int)stack_a->size && !(ft_top(stack_b) < stack_a->array[i] && (ft_top(stack_b) > stack_a->array[i + 1] || stack_a->array[i + 1] == get_max(stack_a))))
		i++;
	if (i == (int)stack_a->size - 1 && !(ft_top(stack_b) < stack_a->array[i] && (ft_top(stack_b) > stack_a->array[0] || stack_a->array[0] == get_max(stack_a))))
		i++;
	rot_to_val(stack_a, stack_a->array[i]);
	/*while (!(ft_top(stack_b) < ft_top(stack_a)
			&& (ft_top(stack_b) > ft_bottom(stack_a)
			|| ft_bottom(stack_a) == get_max(stack_a))))
	{
		ft_rotate(stack_a);
		display_stacks(stack_a, stack_b);
	}*/
	//display_stacks(stack_a, stack_b);
}

void	sort_big(t_stack *stack_a, t_stack *stack_b, int div)
{
	int	*med;
	int	asize;
	int	i;
	int	j;

	j = 0;
	asize = stack_a->size;
	med = make_div_array(stack_a, div);
	while (j + 2 <= div)
	{
		i = 0;
		asize = stack_a->size;
		while (i < asize)
		{
			push_or_rot(stack_a, stack_b, med, j);
			i++;
		}
		j += 2;
	}
	i = 0;
	while (stack_b->size)
	{
		//rotate_to_closeset(stack_a, stack_b);
		rot_to_pos(stack_a, stack_b);
		//write(1, "ban\n", 4);
		ft_push(stack_b, stack_a);
		i++;
	}
	while (!ft_issorted(stack_a))
		ft_rotate(stack_a);
	//display_stacks(stack_a, stack_b);
	/*while (stack_b->size)
	{
		rot_to_val(stack_b, get_next_smaller(stack_a, stack_b));
		ft_push(stack_b, stack_a);
	}*/
	//sort_between(stack_a, stack_b);
	free(med);
}

