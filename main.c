/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:02:44 by myaccount         #+#    #+#             */
/*   Updated: 2022/08/22 17:36:57 by myaccount        ###   ########.fr       */
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
	write(1, "|", 1);
}

void	display_stacks(t_stack *stack_a, t_stack *stack_b)
{
	write(1, "a | ", 4);
	ft_putnums(stack_a->array, stack_a->size);
	write(1, "\nb | ", 4);
	ft_putnums(stack_b->array, stack_b->size);
}

int	main(int ac, char **av)
{
	int	i;
	t_stack *stack_a;
	t_stack *stack_b;

	i = 2;
	if (ac < 2)
	{
		printf("not enough arguments!\n");
		return (0);
	}
	stack_a = malloc(sizeof (t_stack));
	stack_b = malloc(sizeof (t_stack));
	if (av[1][0] == 'd')
	{
		stack_a->max = atoi(av[i]);
		stack_a->array = (int *)malloc(stack_a->max * sizeof (int));
		while (av[++i])
		{
			//printf("[%d]:%d\n", i, atoi(av[i]));
			stack_a->array[i - 3] = atoi(av[i]);
			stack_a->size += 1;
		}
		//printf("{%zu}", stack_a->size);
		display_stacks(stack_a, stack_b);
	}
//	else if (av[1][0] == 'e')
	else 
		printf("invalid first arg!\n");
	return (0);
}
