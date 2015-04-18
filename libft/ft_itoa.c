/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 09:48:37 by basle-qu          #+#    #+#             */
/*   Updated: 2014/11/18 10:39:32 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_ten_power(int n)
{
	int i;
	int result;

	i = 1;
	result = 1;
	while (i < n)
	{
		result *= 10;
		i++;
	}
	return (result);
}

static long int	ft_test_null(int n, char *result)
{
	long int k;

	k = (long int)n;
	if (n < 0)
	{
		result[0] = '-';
		k = -k;
	}
	return (k);
}

char			*ft_itoa(int n)
{
	int			c;
	int			i;
	int			p;
	long int	k;
	char		*result;

	i = 1;
	c = n;
	k = (long int)n;
	while (++i && (c >= 10 || c <= -10))
		c /= 10;
	result = (char*)malloc(sizeof(char) * i + (n < 0));
	result[i - 1 + (n < 0)] = '\0';
	p = i - 1 + (n < 0);
	c = p - (n < 0) + 1;
	i = (n < 0) - 1;
	k = ft_test_null(n, &result[0]);
	while (++i < p)
	{
		result[i] = (k / ft_ten_power(--c)) + 48;
		k = k - (k / ft_ten_power(c)) * ft_ten_power(c);
	}
	return (result);
}
