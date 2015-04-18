/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:49:18 by basle-qu          #+#    #+#             */
/*   Updated: 2014/11/11 18:09:01 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putstr_fd(char const *str, int fd)
{
	if (str == NULL)
		return ;
	while (*str)
	{
		write(fd, str, 1);
		str++;
	}
}
