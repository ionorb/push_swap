/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:05:07 by myaccount         #+#    #+#             */
/*   Updated: 2022/08/26 20:35:19 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int		*array;
	size_t	size;
	size_t	max;
	char	type;
}	t_stack;

//push
void	ft_push(t_stack *from, t_stack *to);

//swap
void	ft_swap(t_stack *stack);
void	ft_sa(t_stack *stack_a);
void	ft_sb(t_stack *stack_b);
void	ft_ss(t_stack *stack_a, t_stack *stack_b);

//rotate
void	ft_rotate(t_stack *stack);
void	ft_revrotate(t_stack *stack);
void	ft_ra(t_stack *stack_a);
void	ft_rb(t_stack *stack_b);
void	ft_rr(t_stack *stack_a, t_stack *stack_b);
void	ft_rra(t_stack *stack_a);
void	ft_rrb(t_stack *stack_b);
void	ft_rrr(t_stack *stack_a, t_stack *stack_b);

//algorithms
void	three_number_algo(t_stack *stack_a);

//libft
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strcmp(char *s1, char *s2);

#endif
