/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visualize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 17:47:26 by mchevall          #+#    #+#             */
/*   Updated: 2016/03/17 17:22:42 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				horizontal_sweep(t_param *e)
{
	int		i;
	int		j;
	t_coord	*c;

	i = -1;
	j = 0;
	c = (t_coord *)ft_memalloc(sizeof(t_coord));
	while (e->intmap[++i])
	{
		c->x1 = e->ow + e->px * (j - i);
		c->y1 = e->oh + e->px * (i - e->intmap[i][j] * e->cz);
		c->x0 = c->x1;
		c->y0 = c->y1;
		while (j <= e->maplen[i])
		{
			c->x1 = e->ow + e->px * (j - i);
			c->y1 = e->oh + e->px *
				(i - e->intmap[i][j] * e->cz);
			diag_line_tracer(e, c);
			c->x0 = c->x1;
			c->y0 = c->y1;
			j++;
		}
		j = 0;
	}
}

void				vertical_sweep(t_param *e)
{
	int		i;
	int		j;
	t_coord	*c;

	i = 0;
	j = -1;
	c = (t_coord *)ft_memalloc(sizeof(t_coord));
	while (++j <= e->maplen[i])
	{
		c->x1 = e->ow + e->px * (j - i);
		c->y1 = e->oh + e->px *
			(i - e->intmap[i][j] * e->cz) - 1;
		c->x0 = c->x1;
		c->y0 = c->y1;
		while (e->intmap[i])
		{
			c->x1 = e->ow + e->px * (j - i) - 1;
			c->y1 = e->oh + e->px * (i - e->intmap[i][j] * e->cz);
			diag_line_tracer(e, c);
			c->x0 = c->x1;
			c->y0 = c->y1;
			i++;
		}
		i = 0;
	}
}
