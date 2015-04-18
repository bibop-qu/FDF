/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 17:25:39 by basle-qu          #+#    #+#             */
/*   Updated: 2015/01/25 16:03:53 by basle-qu         ###   ########.fr       */
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
	if (keycode == 65451)
	{
		e->space += 5;
		expose_hook(e);
	}
	if (keycode == 65453)
	{
		if ((e->space - 5) >= 0)
			e->space -= 5;
		expose_hook(e);
	}
	if (keycode == 119)
	{
		e->coef_z += 0.2;
		expose_hook(e);
	}
	if (keycode == 115)
	{
		e->coef_z -= 0.2;
		expose_hook(e);
	}
	return (0);
}

int		move(int keycode, t_env *e)
{
	if (keycode == 65361)
	{
		e->origin[0] -= 20;
		expose_hook(e);
	}
	if (keycode == 65363)
	{
		e->origin[0] += 20;
		expose_hook(e);
	}
	if (keycode == 65364)
	{
		e->origin[1] += 20;
		expose_hook(e);
	}
	if (keycode == 65362)
	{
		e->origin[1] -= 20;
		expose_hook(e);
	}
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 65307)
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
