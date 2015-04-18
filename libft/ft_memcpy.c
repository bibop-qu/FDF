/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:52:22 by basle-qu          #+#    #+#             */
/*   Updated: 2015/01/14 19:29:14 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t					i;
	unsigned int			dstlen;
	unsigned char			*ptrdst;
	const unsigned char		*ptrsrc;

	i = 0;
	if (!dst)
		return (NULL);
	dstlen = (unsigned int)ft_strlen(dst);
	ptrdst = dst;
	ptrsrc = src;
	if (n <= dstlen)
	{
		while (n > 0)
		{
			ptrdst[i] = ptrsrc[i];
			i++;
			n--;
		}
	}
	else
		ft_memmove(dst, src, n);
	return (dst);
}
