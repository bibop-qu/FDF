/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 09:44:47 by basle-qu          #+#    #+#             */
/*   Updated: 2015/01/14 20:48:25 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int				i;
	unsigned int	result;

	i = 0;
	result = 0;
	if (*str == '\033' || *str == '\200')
		return (0);
	while (!ft_isprint(*str) || *str == ' ')
		str++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	if (str[0] == '-')
		result = -result;
	return (result);
}
