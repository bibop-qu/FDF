/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:52:27 by basle-qu          #+#    #+#             */
/*   Updated: 2014/11/12 18:34:26 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*tmp;

	i = 0;
	tmp = (char*)malloc(sizeof(char) * len + 1);
	while (i < len)
	{
		tmp[i] = ((char*)src)[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		((char*)dst)[i] = tmp[i];
		i++;
	}
	return (dst);
}
