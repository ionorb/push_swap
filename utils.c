/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:05:13 by myaccount         #+#    #+#             */
/*   Updated: 2022/08/26 20:50:14 by myaccount        ###   ########.fr       */
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

int	ft_strcmp(char *s2, char *s1)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	result;

	result = nmemb * size;
	p = malloc(result);
	if (!p)
		return (NULL);
	ft_bzero(p, result);
	return (p);
}
