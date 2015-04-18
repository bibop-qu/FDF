/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 16:56:37 by basle-qu          #+#    #+#             */
/*   Updated: 2015/03/31 16:46:04 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		verif_size(char *line, int *size)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = ft_strsplit(line, ' ');
	while (tmp[i])
		i++;
	if (*size == 0)
	{
		*size = i;
		return (1);
	}
	else
	{
		if (i == *size)
			return (1);
	}
	return (0);
}

int		verif_line(char *line, int *size)
{
	int		i;

	i = 0;
	if (line == NULL)
		return (0);
	while (line[i] && (ft_isdigit(line[i]) ||
			line[i] == ' ' || line[i] == '+' || line[i] == '-'))
	{
		if (line[i + 1] == '\0')
			return (verif_size(line, size));
		i++;
	}
	return (0);
}
