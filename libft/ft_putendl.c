/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:45:43 by basle-qu          #+#    #+#             */
/*   Updated: 2014/11/11 18:06:28 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putendl(char *str)
{
	if (str == NULL)
		return ;
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}
