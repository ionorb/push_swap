/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:05:07 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/06 10:04:27 by myaccount        ###   ########.fr       */
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

int		*easy_sort(t_stack *stack_a);
//push
void	ft_push(t_stack *from, t_stack *to);
void	ft_swap(t_stack *stack);

//rotate
void	ft_rotate(t_stack *stack);
void	ft_revrotate(t_stack *stack);

//algorithms
void	sort_small_stack(t_stack *stack_a, t_stack *stack_b);
void	sort_big(t_stack *stack_a, t_stack *stack_b, int div);

//utils
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_putnum(int n);
int		ft_isnum(char *str);

//stack_utils
int		ft_top(t_stack *stack);
int		ft_issorted(t_stack *stack);
void	rot_to_val(t_stack *stack, int val);
int		get_max(t_stack *stack);
int		get_min(t_stack *stack);

//display
void	display_stacks(t_stack *stack_a, t_stack *stack_b);
void	ft_printarray(int *array, int size);

//initialize
int		ft_get_stack_size(char **av);
t_stack	*initialize_stack(char **av, char c);
t_stack	*initialize_empty_stack(char **av, char c);
void	free_stacks(t_stack *stack_a, t_stack *stack_b);

//parsing
int		ft_parsing(char **av);
#endif
