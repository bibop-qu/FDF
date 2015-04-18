/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 17:58:59 by basle-qu          #+#    #+#             */
/*   Updated: 2015/01/08 16:23:39 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char			*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*cpy;

	if (!s)
		return (NULL);
	i = 0;
	cpy = (char*)malloc(sizeof(char) * len + 1);
	if (!cpy)
		return (NULL);
	while (i < len)
	{
		cpy[i] = s[start];
		start++;
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
