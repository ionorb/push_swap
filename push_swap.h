/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:05:07 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/04 21:00:21 by myaccount        ###   ########.fr       */
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
void	four_number_algo(t_stack *stack_a, t_stack *stack_b);
void	five_number_algo(t_stack *stack_a, t_stack *stack_b);
void	sort_small_stack(t_stack *stack_a, t_stack *stack_b);
void	sort_big(t_stack *stack_a, t_stack *stack_b);

//utils
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strcmp(char *s1, char *s2);
void	ft_putnum(int n);
int		ft_isnum(char *str);

//stack_utils
int		ft_top(t_stack *stack);
int		ft_issorted(t_stack *stack);
int		ft_ismax(t_stack *stack, int n);
int		ft_ismin(t_stack *stack, int n);
//stack_utils_2
void	rot_to_min(t_stack *stack);
void	rot_to_max(t_stack *stack);
int		get_max(t_stack *stack);
int		get_min(t_stack *stack);
//median
int		ft_median(t_stack *stack_a);

//display
void	display_stacks(t_stack *stack_a, t_stack *stack_b);
void	ft_printarray(int *array, int size);

//initialize
int		ft_get_stack_size(char **av);
t_stack	*initialize_stack(char **av, char c);
t_stack	*initialize_empty_stack(char **av, char c);

//parsing
int		ft_parsing(char **av);
#endif
