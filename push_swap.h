/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:05:07 by myaccount         #+#    #+#             */
/*   Updated: 2022/08/22 19:27:44 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_stack 
{
	int	*array;
	size_t size;
	size_t max;
}	t_stack;

int	ft_strcmp(char *s1, char *s2);

void	ft_swap(t_stack *stack);

void	ft_push(t_stack *from, t_stack *to);

void	ft_rotate(t_stack *stack);
#endif
