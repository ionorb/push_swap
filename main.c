/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:02:44 by myaccount         #+#    #+#             */
/*   Updated: 2022/08/22 19:11:19 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putnum(int n)
{
	char	c;

	if (n > 9)
		ft_putnum(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	ft_putnums(int *array, int size)
{
	int	i;
	
	i = 0;
	while (i < size)
	{
		ft_putnum(array[i]);
		write(1, " ", 1);
		i++;
	}
	write(1, "|\n", 2);
}

void	display_stacks(t_stack *stack_a, t_stack *stack_b)
{
	write(1, "a | ", 4);
	ft_putnums(stack_a->array, stack_a->size);
	write(1, "b | ", 4);
	ft_putnums(stack_b->array, stack_b->size);
}

int	main(int ac, char **av)
{
	int	i;
	t_stack *stack_a;
	t_stack *stack_b;

	i = 1;
	if (ac < 2)
	{
		printf("not enough arguments!\n");
		return (0);
	}
	stack_a = malloc(sizeof (t_stack));
	stack_b = malloc(sizeof (t_stack));
	stack_a->max = atoi(av[i]);
	stack_a->array = (int *)malloc(stack_a->max * sizeof (int));
	while (av[++i][0] >= '0' && av[i][0] <= '9')
	{
		stack_a->array[i - 2] = atoi(av[i]);
		stack_a->size += 1;
	}
	write(1, "before:\n", 8);
	display_stacks(stack_a, stack_b);
	while (av[i])
	{
		if (ft_strcmp(av[i], "sa"))
			ft_swap(stack_a);
		else if (ft_strcmp(av[i], "pb"))
			ft_push(stack_a, stack_b);
		i++;
	}
	write(1, "\nafter:\n", 8);
	display_stacks(stack_a, stack_b);
	return (0);
}
