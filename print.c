/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 18:09:20 by basle-qu          #+#    #+#             */
/*   Updated: 2015/01/25 17:16:22 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned long	define_color(int z)
{
	return (0x00FF00 + (0xFF0000 * z));
}

void			draw_line(int *var, t_env *e, t_tmp *tmp)
{
	while (42)
	{
		if (var[6] + e->origin[0] > 0 && var[6] + e->origin[0] < WIN_SIZE_X &&
			var[7] + e->origin[1] > 0 && var[7] + e->origin[1] < WIN_SIZE_Y)
			mlx_pixel_put(e->mlx, e->win, var[6] + e->origin[0],
						var[7] + e->origin[1], define_color(tmp->z));
		if (var[6] == var[8] && var[7] == var[9])
			break ;
		var[5] = var[4];
		if (var[5] > -var[0])
		{
			var[4] -= var[2];
			var[6] += var[1];
		}
		if (var[5] < var[2])
		{
			var[4] += var[0];
			var[7] += var[3];
		}
	}
}

void			init_draw_line(t_env *e, t_tmp *tmp)
{
	int	var[10];

	var[0] = abs(tmp->x1 - tmp->x0);
	var[1] = tmp->x0 < tmp->x1 ? 1 : -1;
	var[2] = abs(tmp->y1 - tmp->y0);
	var[3] = tmp->y0 < tmp->y1 ? 1 : -1;
	var[4] = (var[0] > var[2] ? var[0] : -var[2]) / 2;
	var[5] = 0;
	var[6] = tmp->x0;
	var[7] = tmp->y0;
	var[8] = tmp->x1;
	var[9] = tmp->y1;
	draw_line(var, e, tmp);
}

void			make_draw(t_env *e, t_tmp *tmp, int x, int y)
{
	tmp->x0 = (x - y) * e->space;
	tmp->y0 = ((x + y) - (e->coef_z * e->map[y][x])) * (e->space / 2);
	tmp->z = (e->coef_z * e->map[y][x]);
	if ((x + 1) < e->size_line)
	{
		tmp->x1 = ((x + 1) - y) * e->space;
		tmp->y1 = (((x + 1) + y) - (e->coef_z * e->map[y][x + 1]))
			* (e->space / 2);
		init_draw_line(e, tmp);
	}
	if (e->map[y + 1])
	{
		tmp->x1 = (x - (y + 1)) * e->space;
		tmp->y1 = ((x + (y + 1)) - (e->coef_z * e->map[y + 1][x]))
			* (e->space / 2);
		init_draw_line(e, tmp);
	}
}

void			draw(t_env *e)
{
	int		y;
	int		x;
	t_tmp	*tmp;

	y = 0;
	tmp = (t_tmp*)malloc(sizeof(t_tmp));
	while (e->map[y])
	{
		x = 0;
		while (x < e->size_line)
		{
			make_draw(e, tmp, x, y);
			x++;
		}
		y++;
	}
}
