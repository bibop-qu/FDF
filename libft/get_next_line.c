/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 17:44:59 by basle-qu          #+#    #+#             */
/*   Updated: 2015/02/13 20:17:28 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		init_save(int const fd, char *buff, char *save[fd])
{
	char	*tmp;
	char	*bn;
	int		ret;

	ret = 0;
	while (!(bn = ft_strchr(save[fd], '\n')) &&
		(ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = save[fd];
		save[fd] = ft_strjoin(tmp, buff);
		ft_strdel(&tmp);
	}
	if (ret == -1)
		return (-1);
	if (ret == 0 && !bn)
		return (0);
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	static char	*save[256];
	char		*tmp;
	int			res;
	char		buff[BUFF_SIZE + 1];

	if (fd < 0 || !line)
		return (-1);
	if (!save[fd])
		save[fd] = ft_strnew(1);
	if ((res = init_save(fd, buff, &*save)) == -1)
		return (-1);
	if (res == 0)
	{
		*line = save[fd];
		save[fd] = NULL;
		return (0);
	}
	*line = ft_strsub(save[fd], 0, ft_strchr(save[fd], '\n') - save[fd]);
	tmp = save[fd];
	save[fd] = ft_strdup(ft_strchr(save[fd], '\n') + 1);
	ft_strdel(&tmp);
	return (1);
}
