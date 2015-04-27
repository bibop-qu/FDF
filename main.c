/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 17:25:39 by basle-qu          #+#    #+#             */
/*   Updated: 2015/04/27 11:21:01 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	draw(e);
	return (0);
}

int		zoom(int keycode, t_env *e)
{
	if (keycode == 69)
	{
		e->space += 5;
		expose_hook(e);
	}
	if (keycode == 78)
	{
		if ((e->space - 5) >= 0)
			e->space -= 5;
		expose_hook(e);
	}
	if (keycode == 13)
	{
		e->coef_z += 0.2;
		expose_hook(e);
	}
	if (keycode == 1)
	{
		if ((e->coef_z - 0.2) >= 0)
			e->coef_z -= 0.2;
		else
			e->coef_z = 0;
		expose_hook(e);
	}
	return (0);
}

int		move(int keycode, t_env *e)
{
	if (keycode == 123)
	{
		e->origin[0] -= 20;
		expose_hook(e);
	}
	if (keycode == 124)
	{
		e->origin[0] += 20;
		expose_hook(e);
	}
	if (keycode == 125)
	{
		e->origin[1] += 20;
		expose_hook(e);
	}
	if (keycode == 126)
	{
		e->origin[1] -= 20;
		expose_hook(e);
	}
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	move(keycode, e);
	zoom(keycode, e);
	return (0);
}

int		main(int ac, char **av)
{
	t_env	*e;
	char	**map;

	if (ac != 2)
		write(2, "Wrong number of arguments\n", 26);
	else
	{
		if (verif_map(av[1]) != 1)
		{
			write(2, "Map error!\n", 11);
			exit(0);
		}
		else
		{
			map = recup_arg(av);
			e = (t_env *)malloc(sizeof(t_env));
			init_env(e, map);
			mlx_expose_hook(e->win, expose_hook, e);
			mlx_hook(e->win, 2, 3, key_hook, e);
			mlx_loop(e->mlx);
		}
	}
	return (0);
}
