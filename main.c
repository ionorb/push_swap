/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:02:44 by myaccount         #+#    #+#             */
/*   Updated: 2023/01/21 16:20:05 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		len = -1;
	else if (len <= 5)
		sort_small_stack(stack_a, stack_b);
	else if (len < 150)
		sort_big(stack_a, stack_b, 10);
	else
		sort_big(stack_a, stack_b, 16);
	free_stacks(stack_a, stack_b);
	return (0);
}
