/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:32:32 by basle-qu          #+#    #+#             */
/*   Updated: 2014/11/11 18:05:43 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char const *str)
{
	if (str == NULL)
		return ;
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}
