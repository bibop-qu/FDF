/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 16:23:39 by basle-qu          #+#    #+#             */
/*   Updated: 2015/01/14 20:47:08 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strrchr(const char *s, int c)
{
	int i;

	if (!s)
		return (NULL);
	i = (int)ft_strlen((char*)s);
	while (i >= 0)
	{
		if ((char)s[i] == (char)c)
			return ((char*)&s[i]);
		i--;
	}
	return (0);
}
