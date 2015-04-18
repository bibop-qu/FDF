/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:50:03 by basle-qu          #+#    #+#             */
/*   Updated: 2014/11/11 19:38:36 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;

	j = 0;
	if (!s1 || !s2)
		return (0);
	if (!s2[0])
		return ((char*)s1);
	while (s1[j] != '\0')
	{
		i = 0;
		while (s1[j + i] == s2[i])
		{
			i++;
			if (s2[i] == '\0')
				return ((char*)s1 + j);
		}
		j++;
	}
	return (NULL);
}
