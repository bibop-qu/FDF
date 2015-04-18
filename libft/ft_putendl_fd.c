/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:50:33 by basle-qu          #+#    #+#             */
/*   Updated: 2015/01/02 16:38:23 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putendl_fd(char const *str, int fd)
{
	if (str == NULL)
		return ;
	while (*str)
	{
		write(fd, str, 1);
		str++;
	}
	write(fd, "\n", 1);
}
