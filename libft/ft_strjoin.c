/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:05:29 by basle-qu          #+#    #+#             */
/*   Updated: 2014/11/12 18:05:30 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;

	if (!s1 && !s2)
		return (NULL);
	if (!(s = ft_strnew(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1)))
		return (NULL);
	if (!s1)
		ft_strcpy(s, s2);
	else if (!s2)
		ft_strcpy(s, s1);
	else
	{
		ft_strcpy(s, s1);
		ft_strcat(s, (char*)s2);
	}
	return (s);
}
