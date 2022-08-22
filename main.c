/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:02:44 by myaccount         #+#    #+#             */
/*   Updated: 2022/08/22 16:00:57 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		while (av[++i])
		{
			//printf("[%d]:%d\n", i, atoi(av[i]));
			stack_a->array = (int *)malloc(stack_a->max * sizeof (int));
			stack_a->array[i - 3] = atoi(av[i]);
			stack_a->size += 1;
		}
		//printf("{%zu}", stack_a->size);
	}
//	else if (av[1][0] == 'e')
	else 
		printf("invalid first arg!\n");
	return (0);
}
