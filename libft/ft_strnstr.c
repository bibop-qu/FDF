/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 16:24:26 by basle-qu          #+#    #+#             */
/*   Updated: 2014/11/18 10:11:28 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int			i;
	size_t		j;

	j = 0;
	if (s2[0] == 0)
		return ((char*)s1);
	while (*s1 && j < n)
	{
		if (*s1 == *s2)
		{
			i = 0;
			while (s1[i] == s2[i] && j + i < n)
			{
				i++;
				if (s2[i] == 0)
					return ((char*)s1);
			}
		}
		s1++;
		j++;
	}
	return (0);
}
