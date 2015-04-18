/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 17:23:46 by basle-qu          #+#    #+#             */
/*   Updated: 2015/01/25 17:15:22 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <math.h>

# define WIN_SIZE_X 1024
# define WIN_SIZE_Y 768

typedef	struct	s_env
{
	void		*mlx;
	void		*win;
	int			origin[2];
	int			space;
	int			**map;
	double		coef_z;
	int			size_line;
}				t_env;

typedef struct	s_tmp
{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			z;
}				t_tmp;

int				verif_line(char *line, int *size);
int				verif_map(char *av);
char			**ft_realloc(char **map, char *line);
char			**recup_arg(char **av);
int				**map_int(char **map, t_env *e);
void			draw(t_env *e);
void			init_env(t_env *e, char **map);

#endif
