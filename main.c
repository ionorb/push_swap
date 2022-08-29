/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:02:44 by myaccount         #+#    #+#             */
/*   Updated: 2022/08/29 20:39:16 by myaccount        ###   ########.fr       */
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
	int		len;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
	len = ft_parsing(av + 1);
	if (len == -1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	stack_a = initialize_stack(av + 1, 'a');
	stack_b = initialize_empty_stack(av + 1, 'b');
	if (ft_issorted(stack_a))
		return (0);
	write(1, "before:\n", 8);
	display_stacks(stack_a, stack_b);
	if (len <= 500)
		sort_big(stack_a, stack_b);
		//sort_small_stack(stack_a, stack_b);
	write(1, "\nafter:\n", 8);
	display_stacks(stack_a, stack_b);
	return (0);
}
