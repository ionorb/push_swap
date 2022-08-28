/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 21:31:25 by myaccount         #+#    #+#             */
/*   Updated: 2022/08/26 21:34:10 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_stack_size(char **av)
{
	int	i;

	i = 0;
	while (av[i] && av[i][0] >= '0' && av[i][0] <= '9')
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
	i = stack->size;
	stack->type = c;
	stack->array = (int *)malloc(stack->max * sizeof (int));
	while (--i >= 0)
		stack->array[i] = atoi(av[stack->size - i - 1]);
	return (stack);
}

t_stack	*initialize_empty_stack(int n, char c)
{
	t_stack	*stack;

	stack = malloc(sizeof (t_stack));
	stack->max = n;
	stack->type = c;
	stack->array = (int *)malloc(stack->max * sizeof (int));
	stack->size = 0;
	return (stack);
}