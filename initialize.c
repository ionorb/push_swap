/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 21:31:25 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/08 17:42:31 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_stack_size(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

t_stack	*initialize_stack(char **av, char c)
{
	int		i;
	t_stack	*stack;

	stack = malloc(sizeof (t_stack));
	stack->max = ft_get_stack_size(av);
	stack->size = stack->max;
	stack->type = c;
	stack->array = (int *)malloc(stack->max * sizeof (int));
	i = stack->size;
	while (--i >= 0)
		stack->array[i] = ft_atoi(av[stack->size - i - 1]);
	return (stack);
}

t_stack	*initialize_empty_stack(char **av, char c)
{
	t_stack	*stack;

	stack = malloc(sizeof (t_stack));
	stack->max = ft_get_stack_size(av);
	stack->type = c;
	stack->array = (int *)malloc(stack->max * sizeof (int));
	stack->size = 0;
	return (stack);
}

void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->array);
	free(stack_a);
	free(stack_b->array);
	free(stack_b);
}
