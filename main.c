/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:02:44 by myaccount         #+#    #+#             */
/*   Updated: 2022/08/26 22:23:25 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	perform_operations(char *op, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strcmp(op, "sa"))
		ft_sa(stack_a);
	else if (ft_strcmp(op, "sb"))
		ft_sa(stack_b);
	else if (ft_strcmp(op, "ss"))
		ft_ss(stack_a, stack_b);
	else if (ft_strcmp(op, "pb"))
		ft_push(stack_a, stack_b);
	else if (ft_strcmp(op, "pa"))
		ft_push(stack_b, stack_a);
	else if (ft_strcmp(op, "ra"))
		ft_ra(stack_a);
	else if (ft_strcmp(op, "rb"))
		ft_rb(stack_b);
	else if (ft_strcmp(op, "rr"))
		ft_rr(stack_a, stack_b);
	else if (ft_strcmp(op, "rra"))
		ft_rra(stack_a);
	else if (ft_strcmp(op, "rrb"))
		ft_rrb(stack_b);
	else if (ft_strcmp(op, "rrr"))
		ft_rrr(stack_a, stack_b);
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
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
	{
		printf("not enough arguments!\n");
		return (0);
	}
	stack_a = initialize_stack(av + 2, 'a');
	stack_b = initialize_empty_stack(ft_get_stack_size(av + 2), 'b');
	if (av[1][0] == 'e')
		execute_operations(av + 2, stack_a, stack_b);
	else if (av[1][0] == 'r')
	{
		write(1, "before:\n", 8);
		display_stacks(stack_a, stack_b);
		//three_number_algo(stack_a);
		five_number_algo(stack_a, stack_b);
		write(1, "\nafter:\n", 8);
		display_stacks(stack_a, stack_b);
	}
	return (0);
}
