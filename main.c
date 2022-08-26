/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:02:44 by myaccount         #+#    #+#             */
/*   Updated: 2022/08/26 15:48:30 by myaccount        ###   ########.fr       */
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

void	perform_operations(char *op, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strcmp(op, "sa"))
		ft_swap(stack_a);
	else if (ft_strcmp(op, "sb"))
		ft_swap(stack_b);
	else if (ft_strcmp(op, "ss"))
	{
		ft_swap(stack_a);
		ft_swap(stack_b);
	}
	else if (ft_strcmp(op, "pb"))
		ft_push(stack_a, stack_b);
	else if (ft_strcmp(op, "pa"))
		ft_push(stack_b, stack_a);
	else if (ft_strcmp(op, "ra"))
		ft_rotate(stack_a);
	else if (ft_strcmp(op, "rb"))
		ft_rotate(stack_b);
	else if (ft_strcmp(op, "rr"))
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
	}
	else if (ft_strcmp(op, "rra"))
		ft_revrotate(stack_a);
	else if (ft_strcmp(op, "rrb"))
		ft_revrotate(stack_b);
	else if (ft_strcmp(op, "rrr"))
	{
		ft_revrotate(stack_a);
		ft_revrotate(stack_b);
	}
}

t_stack	*initialize_stack(char **av)
{
	int	i;
	t_stack	*stack;

	i = 0;
	stack = malloc(sizeof (t_stack));
	stack->max = atoi(av[i++]);
	stack->size = 0;
	stack->array = (int *)malloc(stack->max * sizeof (int));
	while (av[i] && av[i][0] >= '0' && av[i][0] <= '9')
	{
		stack->array[i - 1] = atoi(av[i]);
		stack->size += 1;
		i++;
	}
	return (stack);
}

t_stack	*initialize_empty_stack(int n)
{
	t_stack	*stack;

	stack = malloc(sizeof (t_stack));
	stack->max = n;
	stack->array = (int *)malloc(stack->max * sizeof (int));
	stack->size = 0;
	return (stack);
}

void	execute_operations(char **av, t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	write(1, "before:\n", 8);
	display_stacks(stack_a, stack_b);
	write(1, "\n", 1);
	while (av[i][0] >= '0' && av[i][0] <= '9')
		i++;
	while (av[i] && av[i][0] >= 'p' && av[i][0] <= 's')
	{
		perform_operations(av[i], stack_a, stack_b);
		i++;
	}
	write(1, "\nafter:\n", 8);
	display_stacks(stack_a, stack_b);
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
	stack_a = initialize_stack(av + 2);
	stack_b = initialize_empty_stack(100);
	if (av[i][0] == 'e')
		execute_operations(av + 2, stack_a, stack_b);
	else if (av[i][0] == 'r')
	{
		write(1, "before:\n", 8);
		display_stacks(stack_a, stack_b);
		three_number_algo(stack_a);
		write(1, "\nafter:\n", 8);
		display_stacks(stack_a, stack_b);
	}
	return (0);
}
