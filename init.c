/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 19:54:50 by basle-qu          #+#    #+#             */
/*   Updated: 2015/02/13 20:18:08 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		verif_map(char *av)
{
	int		fd;
	int		count;
	int		size;
	char	*line;

	fd = open(av, O_RDONLY);
	count = 0;
	size = 0;
	if (fd == -1)
		perror("");
	while (get_next_line(fd, &line) == 1)
	{
		if (!verif_line(line, &size))
			return (0);
		count++;
	}
	if (count == 0)
		return (0);
	return (1);
}

char	**ft_realloc(char **map, char *line)
{
	int		i;
	char	**result;

	i = 0;
	if (map == NULL)
	{
		result = (char**)malloc(sizeof(char*) * 2);
		result[i] = ft_strdup(line);
		result[i + 1] = NULL;
	}
	else
	{
		while (map[i])
			i++;
		result = (char**)malloc(sizeof(char*) * (i + 2));
		i = -1;
		while (map[++i])
			result[i] = ft_strdup(map[i]);
		result[i] = ft_strdup(line);
		result[i + 1] = NULL;
	}
	return (result);
}

char	**recup_arg(char **av)
{
	int		fd;
	char	*line;
	char	**map;

	fd = open(av[1], O_RDONLY);
	map = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		map = ft_realloc(map, line);
		free(line);
	}
	return (map);
}

int		**map_int(char **map, t_env *e)
{
	int		y;
	int		x;
	char	**tmp;
	int		**final_map;

	y = 0;
	while (map[y])
		y++;
	final_map = (int**)malloc(sizeof(int*) * (y + 1));
	y = 0;
	while (map[y])
	{
		e->size_line = 0;
		x = -1;
		tmp = ft_strsplit(map[y], ' ');
		while (tmp[e->size_line])
			e->size_line++;
		final_map[y] = (int*)malloc(sizeof(int) * e->size_line);
		while (++x < e->size_line)
			final_map[y][x] = ft_atoi(tmp[x]);
		free(tmp);
		y++;
	}
	final_map[y] = NULL;
	return (final_map);
}

void	init_env(t_env *e, char **map)
{
	e->map = map_int(map, e);
	e->mlx = mlx_init();
	if (e->mlx == 0)
	{
		perror("");
		exit(0);
	}
	e->origin[0] = WIN_SIZE_X / 2;
	e->origin[1] = WIN_SIZE_Y / 3;
	e->space = 20;
	e->coef_z = 0.5;
	e->win = mlx_new_window(e->mlx, WIN_SIZE_X, WIN_SIZE_Y, "42");
}
