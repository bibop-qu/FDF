/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:16:19 by basle-qu          #+#    #+#             */
/*   Updated: 2015/01/14 20:46:15 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strchr(const char *s, int c)
{
	size_t		i;

	i = 0;
	while (i <= ft_strlen((char*)s))
	{
		if (s[i] == (char)c)
			return ((char*)&s[i]);
		i++;
	}
	return (0);
}
