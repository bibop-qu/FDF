/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:41:56 by basle-qu          #+#    #+#             */
/*   Updated: 2015/01/02 15:09:49 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	size_t		i;
	void		*new;

	i = 0;
	new = malloc(size);
	if (!new)
		return (0);
	while (i < size)
	{
		((char*)new)[i] = 0;
		i++;
	}
	return (new);
}
