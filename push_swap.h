/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:05:07 by myaccount         #+#    #+#             */
/*   Updated: 2022/08/26 16:01:39 by myaccount        ###   ########.fr       */
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

void	ft_revrotate(t_stack *stack);

void	three_number_algo(t_stack *stack_a);

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t nmemb, size_t size);

#endif
