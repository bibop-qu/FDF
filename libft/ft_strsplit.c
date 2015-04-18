/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 17:20:48 by basle-qu          #+#    #+#             */
/*   Updated: 2015/01/03 20:18:18 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_count(const char *s, char c)
{
	int	i;
	int counter;

	counter = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i - 1] == c || i == 0))
			counter++;
		i++;
	}
	return (counter);
}

char		**ft_strsplit(const char *s, char c)
{
	char		**ret;
	size_t		i;
	size_t		j;
	size_t		len;

	if (!s || !c)
		return (0);
	ret = ft_memalloc(sizeof(char *) * (ft_count(s, c) + 1));
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len = 0;
			while (s[i + len] && (s[i + len] != c))
				len++;
			ret[j++] = ft_strsub(s, i, len);
			i = i + len;
		}
	}
	ret[j] = NULL;
	return (ret);
}
