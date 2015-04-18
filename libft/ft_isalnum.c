/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:39:07 by basle-qu          #+#    #+#             */
/*   Updated: 2014/11/11 20:03:56 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		ft_isalpha(int c)
{
	if ((c > 96 && c < 123) || (c > 64 && c < 91))
		return (1);
	return (0);
}

static int		ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int				ft_isalnum(int c)
{
	if (ft_isalpha(c) == 1 || ft_isdigit(c) == 1)
		return (1);
	return (0);
}
